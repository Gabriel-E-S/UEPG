const bcrypt = require('bcrypt');
const readlineSync = require('readline-sync');
const saltRounds = 10;
// Gera o hash da senha
async function hashPassword(plainPassword) {
    try {
        const hashedPassword = await bcrypt.hash(plainPassword, saltRounds);
        console.log(`Hash gerado: ${hashedPassword}`);
        return hashedPassword;
    } catch (err) {
        console.error('Erro ao criar o hash:', err);
    }
}
// Verifica se a senha corresponde ao hash
async function verifyPassword(plainPassword, hashedPassword) {
    try {
        const match = await bcrypt.compare(plainPassword, hashedPassword);
        if (match) {
            console.log('Senha correta!');
        } else {
            console.log('Senha incorreta!');
        }
        return match;
    } catch (err) {
        console.error('Erro ao verificar a senha:', err);
    }
}
async function exemplo() {
    const senhaRegistro = readlineSync.question(
        'Digite a senha para registro: ',
        { hideEchoBack: true }
    );
    const hashGerado = await hashPassword(senhaRegistro);
    const senhaLogin = readlineSync.question(
        'Digite a senha para login: ',
        { hideEchoBack: true }
    );
    await verifyPassword(senhaLogin, hashGerado);
    const senhaIncorreta = readlineSync.question(
        'Digite novamente a senha: ',
        { hideEchoBack: true }
    );
    await verifyPassword(senhaIncorreta, hashGerado);
}
exemplo();

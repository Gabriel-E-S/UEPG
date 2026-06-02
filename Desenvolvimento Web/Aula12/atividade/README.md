# Tutorial de execução

## Passo a Passo

1. É necessário instalar as dependências  com o comando:

```bash
npm install cors
```

2. No mysqlWorkbench, execute os dois scripts de criação de banco, tabelas e de usuario para acessar o banco.

3. No terminal execute:

```bash
node index.js
```
4. Para rodar o código, abra o index.html usando a extensão live server do vs code ou clicando no arquivo no navegador de arquivos.

# Solução de Problemas: Conectando Node.js (WSL) ao MySQL (Windows)

Se você está rodando o servidor Node.js dentro do Linux (WSL) e o banco de dados MySQL no Windows, você provavelmente vai se deparar com erros de conexão como ETIMEDOUT ou ECONNREFUSED.

Isso acontece porque o WSL funciona como uma máquina virtual e enxerga o Windows como uma rede externa. Portanto, usar localhost no seu código Node.js não vai funcionar.

Siga o passo a passo abaixo para liberar a comunicação entre os dois ambientes:

## Passo 1: Descobrir o IP correto do Windows
O Node.js no WSL precisa apontar para o IP de rede do Windows (Default Gateway), e não para o localhost.

Abra o terminal do seu Linux (WSL).

Execute o comando:

```Bash
ip route
```

Olhe para a primeira linha do resultado, que começa com default via. O número que aparece logo depois é o IP do Windows.

Exemplo: default via 172.28.96.1 ... (Neste caso, o IP é 172.28.96.1).

Atualize o seu arquivo de conexão no Node.js (index.js) com este IP:

```JavaScript
const db = mysql.createConnection({
  host: 'SEU IP', // Se estiver rodando localmente no cmd, use 'localhost' 
  user: 'nodeuser',
  password: 'node123',
  database: 'meu_banco'
});
```

## Passo 2: Liberar o Firewall do Windows
O Windows bloqueia o acesso à porta do MySQL (3306) vindo do WSL por padrão.

Pressione a tecla Windows, digite PowerShell e clique em Executar como Administrador.

Cole o comando abaixo e aperte Enter para criar uma regra de liberação:

```PowerShell
New-NetFirewallRule -DisplayName "Permitir MySQL WSL" -Direction Inbound -LocalPort 3306 -Protocol TCP -Action Allow
```

## Passo 3: Configurar o MySQL para aceitar conexões externas
Por padrão, o MySQL só aceita conexões vindo do próprio Windows. Precisamos avisá-lo que ele pode aceitar requisições de outros IPs.

Abra o Bloco de Notas como Administrador no Windows.

Vá em Arquivo > Abrir e navegue até a pasta oculta de configurações do MySQL. O caminho padrão costuma ser:

C:\ProgramData\MySQL\MySQL Server 8.0 (A versão pode variar).

Mude a opção no canto inferior direito para Todos os arquivos (.) e abra o arquivo my.ini (ou apenas my).

Aperte Ctrl + F e procure por [mysqld]. Logo abaixo dessa linha, adicione a seguinte configuração:

```
bind-address=0.0.0.0
```
Salve o arquivo e feche o Bloco de Notas.

## Passo 4: Reiniciar o serviço do MySQL
Para que a alteração do Passo 3 faça efeito, você precisa reiniciar o banco de dados.

Pressione Windows + R, digite services.msc e dê Enter.

Na lista de serviços, procure por MySQL80 (ou apenas MySQL).

Clique com o botão direito nele e selecione Reiniciar.

Pronto! Agora é só rodar o seu node index.js no terminal do WSL e a conexão será estabelecida com sucesso! 
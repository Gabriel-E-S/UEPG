var primeiroTermo = '';
var segundoTermo = '';
var operacao = '';

var input = document.querySelector('#inputVisor');

var estado = "primeiroTermo";

console.log(input);

function colocarNoDisplay(elemento){

    if(elemento === '+' || elemento === '-' || elemento === '*' || elemento === '/'){
        estado = "segundoTermo";
        input.value = '';
        operacao = elemento;
        console.log('operacao = ' + operacao);
        return;
    }

    if(estado === "primeiroTermo"){
        primeiroTermo += elemento;
        console.log(primeiroTermo);
        input.value = primeiroTermo;
    }
    if(estado === "segundoTermo"){
        segundoTermo += elemento;
        console.log(segundoTermo);
        input.value = segundoTermo;
    }
}

function limparDisplay(){
    expressao = '';
    primeiroTermo = '';
    segundoTermo = '';
    expressao = '';
    input.value = '';
    estado = "primeiroTermo";
}

function calcular(){    

    try{

        let resultado = 0;

        let rprimeiroTermo = parseFloat(primeiroTermo);
        let rsegundoTermo = parseFloat(segundoTermo);

        console.log(rprimeiroTermo + '| ' + rsegundoTermo);

        switch(operacao){
            case '+': resultado = rprimeiroTermo + rsegundoTermo ; break;
            case '-': resultado = rprimeiroTermo - rsegundoTermo ; break;
            case '*': resultado = rprimeiroTermo * rsegundoTermo ; break;
            case '/': resultado = rprimeiroTermo / rsegundoTermo ; break;
        }
        
        console.log('resultado = ' + resultado);
        primeiroTermo = resultado;
        segundoTermo = '';
        operacao = '';
        estado = "primeiroTermo";
        input.value = resultado;
    }
    catch{
        alert("Erro!");
        input.value = "ERRO";
    }
}

var expressao = '';

function calcularSimples(){    

    try{
        resultado = eval(expressao);
        expressao = resultado;

        input.value = resultado;
    }
    catch{
        alert("Erro!");
        input.value = "ERRO";
    }
}

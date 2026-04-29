console.log('oi mano');

const entradaDeDados = document.querySelector('#entradaDeDados')
const listaTarefas = document.getElementById('listaTarefas');
var listaItens = document.querySelector('.tarefa');

function criarTarefa(){

    console.log('entrada =  ' + entradaDeDados.value);

    let tarefa = entradaDeDados.value.trim();

    if(tarefa === ''){
        alert('Erro, a mensagem não foi preenchida!');
        return;
    }

    let item = document.createElement('li');

    item.textContent = tarefa;
    item.setAttribute('class','tarefa');

    item.addEventListener('click',function(){
        item.classList.toggle('feito');
    });
    
    listaTarefas.appendChild(item);

    entradaDeDados.value = '';
    entradaDeDados.focus();

    listaItens = document.querySelectorAll('.tarefa');
}

document.addEventListener('keydown',function(e){
    if(e.key === 'Enter'){
        criarTarefa();
    }
})
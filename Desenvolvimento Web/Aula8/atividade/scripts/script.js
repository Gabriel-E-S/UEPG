const inputTituloLivro = document.getElementById('inputTituloLivro');
const botaoAdicionar = document.getElementById('botaoAdicionar');
const colunaQueroLer = document.getElementById('queroLer');

let contadorDeLivros = 0;

function addLivro(){
    const tituloLivro = inputTituloLivro.value.trim();

    if(tituloLivro === ''){
        alert("Você esqueceu de digitar o nome do livro");
        return;
    }

    const cartao = document.createElement('div');

    cartao.classList.add('card');

    cartao.setAttribute('draggable','true');

    cartao.id = 'livro-' + contadorDeLivros;

    contadorDeLivros++;

    cartao.textContent = tituloLivro;

    cartao.addEventListener('dragstart',function(e){

        e.dataTransfer.setData('text/plain',cartao.id);

        setTimeout(() => cartao.classList.add('dragging'),0)
    });

    cartao.addEventListener('dragend',function(){
        cartao.classList.remove('dragging');
    });

    colunaQueroLer.appendChild(cartao);
    inputTituloLivro.value = '';
    inputTituloLivro.focus();
}

const colunas = document.querySelectorAll('.coluna');

colunas.forEach(coluna =>{
    coluna.addEventListener('dragover',function(e){
        e.preventDefault();
        coluna.classList.add('dragOver');
    })

    coluna.addEventListener('dragleave',function(){
        coluna.classList.remove('dragOver');
    });

    coluna.addEventListener('drop',function(e){
        e.preventDefault();
        coluna.classList.remove('dragOver');

        const idElementoArrastado = e.dataTransfer.getData('text/plain');
        const cartaoArrastado = document.getElementById(idElementoArrastado);

        if(cartaoArrastado){
            coluna.appendChild(cartaoArrastado);
        }
    });

});

botaoAdicionar.addEventListener('click',addLivro);

inputTituloLivro.addEventListener('keypress',function(e){
    if(e.key === 'Enter'){
        addLivro();
    }
});

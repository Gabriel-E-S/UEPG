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

    const textoDoLivro = document.createElement('span');

    textoDoLivro.textContent = tituloLivro;

    const botaoExcluir = document.createElement('span');
    botaoExcluir.textContent = '✖'; 
    botaoExcluir.classList.add('botaoExcluir');

    botaoExcluir.addEventListener('click', function() {
        cartao.remove();
    });

    cartao.appendChild(textoDoLivro);
    cartao.appendChild(botaoExcluir);

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

console.log(colunas);

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

        cartaoArrastado.classList.remove('corLendo','corLido');

        if(cartaoArrastado){
            coluna.appendChild(cartaoArrastado);
            if(coluna.id === 'lendo'){
                cartaoArrastado.classList.add('corLendo');
            }
            if(coluna.id === 'lido'){
                cartaoArrastado.classList.add('corLido');
            }


        }
    });

});

botaoAdicionar.addEventListener('click',addLivro);

inputTituloLivro.addEventListener('keypress',function(e){
    if(e.key === 'Enter'){
        addLivro();
    }
});

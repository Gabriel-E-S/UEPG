
fetch('http://localhost:3000/filmes')
    .then(resposta => resposta.json())
    .then(filmes => {
        const container = document.getElementById('containerFilmes');
        container.innerHTML = ''; 

        if (filmes.length === 0) {
            container.innerHTML = '<p>Nenhum filme encontrado.</p>';
            return;
        }

        filmes.forEach(tarefa => {
            const dataFormatada = new Date(tarefa.lancamento).toLocaleDateString('pt-BR');
            
            const cardHTML = `
                <div class="cardFilme genero-${tarefa.genero}">
                    <h3>${tarefa.nome}</h3>
                    <p>${tarefa.descricao}</p>
                    <p class="Data de lançamento"><strong>Data de lançamento:</strong> ${dataFormatada}</p>
                    <p><strong>Categoria:</strong> ${tarefa.genero}</p>
                    <button onclick="deletarFilme(${tarefa.id})" style="background-color: #dc3545; color: white; border: none; padding: 5px 10px; cursor: pointer; border-radius: 4px; margin-top: 10px;">
                        🗑️ Remover
                    </button>
                </div>
            `;
            
            container.innerHTML += cardHTML;
        });
    })
    .catch(erro => {
        console.error('Erro ao buscar filmes:', erro);
        document.getElementById('containerFilmes').innerHTML = '<p>Erro ao carregar as filmes.</p>';
    });
    
function deletarFilme(id) {

    const confirmacao = confirm("Tem certeza que deseja remover esta tarefa?");
    
    if (confirmacao) {

        fetch(`http://localhost:3000/filmes/${id}`, {
            method: 'DELETE' 
        })
        .then(resposta => {
            if (resposta.ok) {
                alert("Filme removida com sucesso!");
    
                window.location.reload(); 
            } else {
                alert("Erro ao remover a tarefa.");
            }
        })
        .catch(erro => console.error('Erro na requisição:', erro));
    }
}
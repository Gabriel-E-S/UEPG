fetch('http://localhost:3000/filmes')
    .then(resposta => resposta.json())
    .then(filmes => {
        const container = document.getElementById('containerFilmes');
        container.innerHTML = ''; 

        if (filmes.length === 0) {
            container.innerHTML = '<p>Nenhum filme encontrado.</p>';
            return;
        }

        filmes.forEach((filme, index) => {
            const dataFormatada = new Date(filme.lancamento).toLocaleDateString('pt-BR');
            const nota = filme.nota || 0;
            
            const delayAnimacao = (index + 1) * 0.1;
            
            const cardHTML = `
                <div class="cardFilme genero-${filme.genero}" style="animation-delay: ${delayAnimacao}s">
                    <h3>${filme.nome}</h3>
                    <p>${filme.descricao}</p>
                    <p class="Data de lançamento"><strong>Data de lançamento:</strong> ${dataFormatada}</p>
                    <p><strong>Categoria:</strong> ${filme.genero}</p>
                    
                    <p><strong>Avaliação:</strong> ${nota.toFixed(1)}</p>
                    
                    <button onclick="deletarFilme(${filme.id})" style="background-color: #ff0000; color: white; border: none; padding: 5px 10px; cursor: pointer; border-radius: 4px; margin-top: 10px;">
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
    const confirmacao = confirm("Tem certeza que deseja remover este filme?");
    
    if (confirmacao) {
        fetch(`http://localhost:3000/filmes/${id}`, {
            method: 'DELETE' 
        })
        .then(resposta => {
            if (resposta.ok) {
                alert("Filme removido com sucesso!");
                window.location.reload(); 
            } else {
                alert("Erro ao remover o filme.");
            }
        })
        .catch(erro => console.error('Erro na requisição:', erro));
    }
}
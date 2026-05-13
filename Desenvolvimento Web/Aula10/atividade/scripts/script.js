document.getElementById('btnCarregarComentarios').addEventListener('click', loadComments);
input = document.getElementById('inputId');

input.addEventListener('change', loadComments);

function loadComments() {
    fetch('https://jsonplaceholder.typicode.com/comments')
        .then(response => response.json())
        .then(posts => {
            let output = '';
            posts.forEach(post => {
                if (post.postId == input.value) {
                    output += "<li>" + post.body + "</li>";
                }
            });
            document.getElementById('listaComentarios').innerHTML = output;
        });
}
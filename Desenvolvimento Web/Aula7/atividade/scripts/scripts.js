console.log("Olá, mundo!");

var estado = "parado";
var tempo = 25;

function iniciarContagem() {
    if (estado == "parado" || estado == "pausado") {
        estado = "contando";
        document.getElementById("status").textContent = "Contando";

        const intervalo = setInterval(() => {
            document.getElementById("tempoRestante").textContent = `0:${tempo < 10 ? '0' : ''}${tempo}`;
            
            
            if(tempo < 0) {
                clearInterval(intervalo);
                console.log("Tempo esgotado!");
                estado = "parado";
                return;
            }
            
            if(estado == "parado" || estado == "pausado") {
                clearInterval(intervalo)
            }
            console.log(tempo);
            tempo--;
        }, 1000);    
    }
    else{
        console.log("A contagem já está em andamento.");
        alert("A contagem já está em andamento.");
    }
}

function pararContagem() {
    switch (estado) {
        case "parado":
            console.log("A contagem já está parada.");
            break;
        case "contando":
            estado = "pausado";
            document.getElementById("status").textContent = "Pausado";
            console.log("Contagem pausada.");
            break;
        case "pausado":
            tempo = 25;
            document.getElementById("status").textContent = "Resetado";
            document.getElementById("tempoRestante").textContent = `0:${tempo < 10 ? '0' : ''}${tempo}`;
            console.log("Contagem resetada.");
            estado = "parado";
            break;
    }
}
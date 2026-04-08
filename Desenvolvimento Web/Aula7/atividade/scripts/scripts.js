var estado = "parado";
var tempo = 25;
var intervalo;

function iniciarContagem() {
    if (estado == "parado" || estado == "pausado") {

        if(estado == "parado") {
            tempo = 25;
        }

        estado = "contando";

        document.getElementById("status").textContent = "Contando";

        clearInterval(intervalo);

        intervalo = setInterval(() => {
            
            const elementoTempo = document.getElementById("tempoRestante");
            
            elementoTempo.textContent = `0:${tempo < 10 ? '0' : ''}${tempo}`;
            
            if (tempo < 10 && tempo > 0) {
                elementoTempo.classList.add("alerta-tempo");
            } else {
                elementoTempo.classList.remove("alerta-tempo");
            }
            
            if(tempo <= 0) {
                clearInterval(intervalo);
                document.getElementById("status").textContent = "Parado";
                
                elementoTempo.classList.remove("alerta-tempo"); 
                
                console.log("Tempo esgotado!");
                
                setTimeout(() => {
                    alert("Tempo esgotado! Tire um tempo para você descansar");
                }, 10);

                estado = "parado";
                return;         
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
            document.getElementById("status").textContent = "Parado";
            console.log("A contagem já está parada.");
            break;
        case "contando":
            estado = "pausado";
            clearInterval(intervalo);
            document.getElementById("status").textContent = "Pausado";
            console.log("Contagem pausada.");
            break;
        case "pausado":
            estado = "parado";
            tempo = 25;     
            document.getElementById("status").textContent = "Resetado";
            
            const elementoTempo = document.getElementById("tempoRestante");
            elementoTempo.textContent = `0:${tempo < 10 ? '0' : ''}${tempo}`;
            
            elementoTempo.classList.remove("alerta-tempo");
            
            console.log("Contagem resetada.");
            break;
    }
}
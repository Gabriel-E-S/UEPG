const button = document.getElementById("enviarPalavra");
const input = document.getElementById("entradaPalavra");

// Substitua pelo endereço IP do seu ESP8266
const ipESP8266 = "http://10.206.255.119";

button.addEventListener('click', function() {
    const textValue = input.value;

    if (textValue.trim() === "") {
        return; 
    }

    const url = `${ipESP8266}/morse?palavra=${encodeURIComponent(textValue)}`;

    fetch(url)
        .then(response => {
            if (response.ok) {
                input.value = ""; 
            }
        })
});
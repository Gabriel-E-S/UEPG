# Revisão para a Prova de Desenvolvimento Web

Este é um guia completo de revisão focado nos fundamentos do Desenvolvimento Web: HTML, CSS, JavaScript, Manipulação do DOM e o básico de PHP para recebimento de formulários. 

---

## Sumário Interativo


<summary>Clique para expandir o sumário</summary>

- [1. HTML (HyperText Markup Language)](#1-html-hypertext-markup-language)
  - [Estrutura Semântica](#estrutura-semântica)
  - [Formulários](#formulários)
  - [Outras tags importantes em formulários](#outras-tags-importantes-em-formulários)
  - [Atributos essenciais para inputs](#atributos-essenciais-para-inputs)
- [2. CSS (Cascading Style Sheets)](#2-css-cascading-style-sheets)
  - [Box Model e Display](#box-model-e-display)
  - [Posicionamento (position)](#posicionamento-position)
  - [Layouts: Flexbox e Grid](#layouts-flexbox-e-grid)
  - [Posicionamento Relativo vs Absoluto](#posicionamento-relativo-vs-absoluto)
  - [Animações em CSS](#animações-em-css)
- [3. JavaScript (Fundamentos e Eventos)](#3-javascript-fundamentos-e-eventos)
  - [Variáveis e Funções](#variáveis-e-funções)
  - [Temporizadores](#temporizadores)
- [4. Manipulação do DOM (Document Object Model)](#4-manipulação-do-dom-document-object-model)
  - [Seleção e Alteração](#seleção-e-alteração)
- [5. Básico de PHP (Backend Simples)](#5-básico-de-php-backend-simples)



---

## 1. HTML (HyperText Markup Language)
O HTML é uma linguagem de marcação (e não de programação) utilizada para estruturar páginas da web. Ele é composto por tags que definem o tipo de conteúdo exibido.

### Estrutura Semântica
Um site típico possui blocos lógicos para organizar o conteúdo:
*   `<header>`: Cabeçalho do site ou seção.
*   `<nav>`: Barra de navegação com links.
*   `<main>`: Conteúdo principal da página.
*   `<footer>`: Rodapé com direitos autorais e contatos.

### Formulários
Sistemas de coleta de informações dos usuários que enviam dados ao servidor.
*   **Atributo `action`**: Define a URL para onde os dados serão enviados.
*   **Atributo `method`**: Define o método HTTP (como `POST` ou `GET`).

No HTML, a tag `<input>` é a principal forma de capturar dados, e seu comportamento muda totalmente com base no atributo `type`. Abaixo estão os tipos mais comuns e os controles adicionais usados em formulários.

### 1. Entradas de texto e senha
* `type="text"`: campo padrão para textos curtos, como nome, cidade ou assunto.
* `type="email"`: campo específico para e-mail, com validação básica de formato.
* `type="password"`: campo para senha, que oculta os caracteres digitados.

### 2. Escolhas e seleções
* `type="checkbox"`: caixa de seleção que permite marcar várias opções ao mesmo tempo.
* `type="radio"`: botão circular para escolha única dentro de um grupo com o mesmo `name`.

### 3. Entradas numéricas
* `type="number"`: permite apenas números e aceita atributos extras:
    * `min`: valor mínimo.
    * `max`: valor máximo.
    * `step`: intervalo de incremento.
* `type="range"`: slider visual para escolher um valor dentro de um intervalo definido.

### 4. Datas e horários
* `type="date"`: exibe um calendário para selecionar uma data.
* `type="time"`: captura um horário.
* `type="datetime-local"`: combina data e hora no mesmo campo.

### 5. Cores
* `type="color"`: abre um seletor de cores nativo do navegador.

### 6. Botões de ação
* `type="submit"`: botão que envia os dados do formulário.
* `type="reset"`: limpa todos os campos do formulário.

---

### Outras tags importantes em formulários
* `<textarea>`: campo de texto longo em várias linhas. Ideal para mensagens, observações ou descrições.
* `<select>` e `<option>`: criam um menu suspenso (dropdown). O valor enviado é o `value` da opção selecionada.
* `<label>`: rótulo que descreve um campo e melhora a usabilidade. Deve associar-se ao `input` com o atributo `for`.

---

### Atributos essenciais para inputs
* `name`: nome do dado enviado ao servidor. Fundamental para backend como PHP.
* `value`: valor padrão do campo.
* `required`: torna o preenchimento obrigatório.
* `placeholder`: texto de orientação exibido dentro do campo até o usuário começar a digitar.

---

```html
<!-- Exemplo de Estrutura e Formulário HTML -->
<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <title>Revisão HTML</title>
</head>
<body>
    <header>
        <h1>Meu Site de Revisão</h1> <!-- Título principal -->
    </header>
    
    <main>
        <section>
            <h2>Contato</h2> <!-- Subtítulo -->
            <!-- Formulário enviando dados de forma oculta via POST para um arquivo PHP -->
            <form action="processa.php" method="POST">
                
                <!-- Rótulo atrelado ao input pelo atributo 'for' e 'id' -->
                <label for="nome">Nome:</label>
                <input type="text" id="nome" name="nome" required placeholder="Digite seu nome"> <!-- Campo de texto obrigatório -->
                
                <label for="turno">Turno Preferido:</label>
                <!-- Radio buttons para escolha única -->
                <input type="radio" id="manha" name="turno" value="manha"> Manhã
                <input type="radio" id="noite" name="turno" value="noite"> Noite
                
                <label for="mensagem">Mensagem:</label>
                <!-- Textarea para textos longos de múltiplas linhas -->
                <textarea id="mensagem" name="mensagem" rows="4"></textarea>
                
                <!-- Botão nativo para enviar os dados -->
                <button type="submit">Enviar</button>
            </form>
        </section>
    </main>
</body>
</html>
```

---

## 2. CSS (Cascading Style Sheets)
O CSS é uma linguagem de folhas de estilos usada para controlar a aparência e o layout das páginas estruturadas no HTML. A melhor prática é usá-lo externamente, vinculando um arquivo `.css` através da tag `<link rel="stylesheet" href="estilo.css">`.

### Box Model e Display
Todo elemento é uma caixa. O tamanho e o comportamento dessa caixa dependem das propriedades visuais:
*   **Margem (`margin`)**: Espaço externo.
*   **Preenchimento (`padding`)**: Espaço interno (entre a borda e o conteúdo).
*   **Display `block`**: Ocupa 100% da largura, ficando um abaixo do outro.
*   **Display `inline`**: Ocupa apenas o espaço do conteúdo, não aceita largura/altura.
*   **Display `inline-block`**: Fica lado a lado, mas aceita controles de dimensão.

### Posicionamento (`position`)
Controla o método de posicionamento do elemento.
*   `static`: Padrão, não aceita coordenadas.
*   `fixed`: Elemento não se move da tela mesmo com rolagem.
*   `sticky`: Fixo em relação ao rolamento da página (gruda ao rolar).
*   `relative`: Move-se a partir da sua posição inicial natural.
*   `absolute`: Removido do fluxo normal; posiciona-se em relação ao ancestral posicionado mais próximo.

### Layouts: Flexbox e Grid
Sistemas modernos para distribuir o layout na página.
*   **Flexbox**: Unidimensional (trabalha linha ou coluna por vez). Ideal para distribuir itens em um único eixo.
*   **Grid**: Bidimensional (trabalha com linhas e colunas simultaneamente).

```css
/* Selecionando por tag, classe (.) e ID (#) */

/* Flexbox */
.menu-flex {
    display: flex; /* Transforma o contêiner em flex */
    flex-direction: row; /* Elementos em linha */
    justify-content: space-between; /* Distribui espaço ao máximo entre os itens */
    align-items: center; /* Centraliza no eixo cruzado (vertical) */
}

/* CSS Grid */
.grade-produtos {
    display: grid; /* Transforma em contêiner grid */
    grid-template-columns: repeat(3, 1fr); /* Cria 3 colunas de tamanhos flexíveis e iguais */
    gap: 20px; /* Cria lacunas/espaços de 20px entre linhas e colunas */
}

.item-destaque {
    grid-column: 1 / 3; /* Faz o item ocupar da linha de coluna 1 até a 3 */
}

/* Transições e Animações */
.botao {
    background-color: blue;
    /* Transição suave de mudança de estado */
    transition: background-color 0.3s ease-in-out; 
}

.botao:hover {
    background-color: red; /* Muda de cor ao passar o mouse */
}

/* Animação com Keyframes */
@keyframes deslizar {
    0% { transform: translateX(0); } /* Estado inicial */
    100% { transform: translateX(300px); } /* Estado final */
}

.animar-caixa {
    /* Propriedade abreviada: nome duração preenchimento */
    animation: deslizar 2s forwards; 
}
```
### Posicionamento Relativo vs Absoluto

No CSS, `position: relative` e `position: absolute` mudam como um elemento se comporta e se desloca.

- `position: relative`
    - usa a própria posição original como ponto de referência
    - se aplicado sozinho, o elemento não sai do lugar
    - ao usar `top`, `bottom`, `left` ou `right`, ele se move a partir da sua posição natural
    - o espaço original do elemento continua reservado, sem bagunçar os vizinhos

- `position: absolute`
    - remove o elemento do fluxo normal da página
    - outros elementos agem como se ele não existisse
    - pode gerar sobreposição
    - posiciona-se em relação ao ancestral posicionado mais próximo (`position: relative`, `absolute`, `fixed` ou `sticky`)

### Como usar juntos

A combinação mais comum é:

- pai: `position: relative`
- filho: `position: absolute`

Assim, o filho fica livre para se mover, mas sempre preso aos limites do pai.

```css
.container {
        position: relative;
}

.item-absoluto {
        position: absolute;
        top: 20px;
        left: 20px;
}
```

Nesse exemplo, `.item-absoluto` se desloca 20 pixels para baixo e 20 pixels para a direita, sempre com relação ao `.container`.

### Animações em CSS

As animações em CSS permitem adicionar movimento e interatividade complexa aos elementos da página de forma nativa, sem a necessidade de utilizar JavaScript . 

Para funcionarem, as animações dependem de **dois componentes fundamentais** atuando em conjunto :

### 1. A Regra `@keyframes`
É aqui que você constrói a "linha do tempo" da animação . O `@keyframes` define a sequência exata de estados e estilos pelos quais o elemento vai passar . Você utiliza porcentagens para marcar esses momentos (de `0%` representando o estado inicial até `100%` para o estado final) .

### 2. Propriedades de Controle (`animation`)
Depois de criar a regra `@keyframes`, você precisa aplicá-la ao elemento HTML desejado e configurar como ela vai rodar usando as sub-propriedades do `animation` :

*   **`animation-name`**: O nome personalizado que você deu à sua regra `@keyframes` .
*   **`animation-duration`**: O tempo total que a animação leva para completar um único ciclo (ex: `3s`) .
*   **`animation-timing-function`**: Controla o ritmo e a aceleração/desaceleração do movimento . Valores comuns incluem `linear` (velocidade constante), `ease` (padrão, acelera e desacelera), `ease-in` (começa devagar) e `ease-out` (termina devagar) .
*   **`animation-delay`**: O tempo de espera/atraso antes da animação começar a rodar na tela .
*   **`animation-iteration-count`**: Quantas vezes a animação deve se repetir. Pode receber um número exato ou o valor `infinite` para rodar em loop contínuo .
*   **`animation-direction`**: Define o fluxo da animação. Pode ser normal, inverso, `alternate` (vai até o fim e volta de ré) ou `alternate-reverse` .
*   **`animation-fill-mode`**: Especifica o estado visual do elemento antes e depois da execução. O valor mais importante é o `forwards`, que faz o elemento manter os estilos do último keyframe ao terminar .
*   **`animation-play-state`**: Permite controlar o estado de reprodução, como o uso de `paused` para paralisar a animação .

### A Propriedade Abreviada (Shorthand)
Em vez de escrever todas as sub-propriedades separadamente, você pode definir todas as regras em uma única linha usando a propriedade `animation` . Para que o navegador interprete corretamente, **é obrigatório seguir esta ordem** :
1. `name` 2. `duration` 3. `timing-function` 4. `delay` 5. `iteration-count` 6. `direction` 7. `fill-mode` 8. `play-state` .

---

### Exemplo de Código Prático

Abaixo, um exemplo de um efeito de **Pulse** (mudança de cor de fundo) e **Fade-In** (surgimento gradual), muito comuns em interfaces modernas:

```css
/* 1. Definindo a linha do tempo das animações */

/* Animação que altera a cor de fundo */
@keyframes pulse {
    0% { background-color: #001F3F; } /* Estado inicial */
    100% { background-color: #FF4136; } /* Estado final */
}

/* Animação que faz o elemento surgir (opacidade de 0 a 1) */
@keyframes fade-in {
    from { opacity: 0; } /* Equivale a 0% */
    to { opacity: 1; }   /* Equivale a 100% */
}

/* 2. Aplicando as animações nos elementos HTML */

.botao-alerta {
    /* Usando a propriedade abreviada: name | duration | iteration-count */
    animation: pulse 5s infinite; 
}

.elemento-surgindo {
    /* Usando a propriedade abreviada: name | duration | timing-function */
    animation: fade-in 2s ease-in-out; 
}

---

## 3. JavaScript (Fundamentos e Eventos)
Linguagem que adiciona interatividade e comportamento lógico à página.

Colocar no html com a tag *script*, dê preferência no final do arquivo. Se o js não funcionar, pelo menos a página carregou toda.


### Variáveis e Funções
*   `let`: Declara variável que respeita blocos `{}`.
*   `const`: Declara uma constante de leitura apenas.
*   **Arrow Functions**: Sintaxe curta para funções usando `=>`.

### Temporizadores
Controlam execuções baseadas em tempo.
*   `setTimeout()`: Executa uma vez após X milissegundos.
*   `setInterval()`: Executa repetidamente a cada X milissegundos.

```javascript
// Exemplo de variáveis e função de seta (Arrow Function)
const mensagemPadrao = "Olá, bem-vindo!";
let exibirMensagem = (nome) => alert(mensagemPadrao + " " + nome); // Sintaxe encurtada

// Temporizador: Executa após 3 segundos (3000ms)
setTimeout(() => {
    console.log("3 segundos se passaram!"); // Mostra no console
}, 3000);

// Exemplo com setInterval: mostra uma mensagem a cada 5 segundos
setInterval(() => {
    alert("setInterval: Isso aparece a cada 5 segundo");
}, 5000);
```

---

## 4. Manipulação do DOM (Document Object Model)
O DOM é a representação orientada a objetos da página, permitindo ao JavaScript alterar dinamicamente estrutura, estilo e conteúdo.

### Seleção e Alteração
*   `querySelector()`: Seleciona o primeiro elemento que atende ao seletor CSS.
*   `textContent`: Altera o texto puro de um elemento.
*   `innerHTML`: Altera o conteúdo permitindo interpretar tags HTML.
*   `classList`: Manipula classes inteiras (`add`, `remove`, `toggle`) de forma eficiente.

```javascript
// Selecionando elementos usando seletores CSS (classe e ID)
const titulo = document.querySelector('#titulo');
const botaoTema = document.querySelector('.btn-tema');

// Alterando texto e estilo diretamente via propriedade style
titulo.textContent = "Novo Título Manipulado!";
titulo.style.color = "blue"; // Propriedades CSS viram camelCase no JS

// Adicionando um Ouvinte de Eventos (Event Listener)
botaoTema.addEventListener('click', function() {
    // Ao clicar, o JS acessa o corpo da página e alterna a classe 'dark-theme'
    // O comando 'toggle' adiciona a classe se não existir, e remove se existir
    document.body.classList.toggle('dark-theme');
});

// Evento de Teclado
document.addEventListener('keydown', function(event) {
    console.log("Tecla pressionada: " + event.key); // Captura qual tecla foi digitada
});
```

---

## 5. Básico de PHP (Backend Simples)
O PHP é utilizado para processar os dados enviados pelos formulários HTML no servidor.

Para capturar esses dados, utilizamos arrays superglobais que correspondem ao `method` escolhido no formulário (`POST` ou `GET`) atrelados ao atributo `name` do campo de entrada.

```php
<?php
// Arquivo: processa.php

// $_POST captura os dados enviados de forma oculta pelo formulário HTML
// O valor entre chaves corresponde ao atributo 'name' do input
$nomeUsuario = $_POST['nome']; 
$mensagemRecebida = $_POST['mensagem'];

// O comando 'echo' imprime (mostra) um resultado na tela
// A tag <br> do HTML pode ser renderizada pelo PHP para quebrar linha
echo "Obrigado por entrar em contato, $nomeUsuario! <br>";
echo "Sua mensagem: $mensagemRecebida";
?>
```
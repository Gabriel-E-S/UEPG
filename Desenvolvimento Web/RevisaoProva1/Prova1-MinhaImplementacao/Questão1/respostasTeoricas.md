# Prova 1 de Dev web - Gabriel do Espírito Santo

## Questão 1 - Explique a diferença entre os comandos de posicionamento static, relative e fixed

Ambos os três comandos são para posionamento de componentes, apresentando suas características próprias

**static:** é o valor que vem padrão nos elementos. Não aceita posicionamento por meio dos comandos de left, bottom, right, top.

**relative:** Permite reposicionar os elementos com base na sua posição gerada com base na estrutura do HTML, de forma relativa à ela.

**fixed:**  Fixa o elemento na tela com base nas posições dadas para ele. Ao rolar a tela o elemento continua fixo no mesmo lugar.

## Questão 2 - Por que hoje em dia é preferível usar os comandos flexbox e grid do que o comando float?

O comando float foi pensado na época para permitir uma maior mixagem entre imagens e texto, permitindo que fossem posicionados textos ao lado de elementos visuais. No entanto, atualmente é mais recomendado o uso de Flexbox e Grid devido a maior complexidade dos problemas e soluções propostos em aplicações web, que exigem uma maior personalização e estillização, condições que são atendidas por eles devido ao seu número maior de elementos de personalização, alinhamento e orientação, além de sua maior abrangência de casos de uso.

## Questão 3 - Explique a diferença entre o eixo principal e o eixo cruzado no flexbox

Por padrão, os eixos principal e eixo cruzado são respectivamente o eixo horizontal e vertical.

Para realizar o alilhamento no eixo principal, usamos o comando: *justify-content*.

No eixo cruzado utilizamos o comando *align-itens*.

A principal diferença entre os dois é o quesito de qual orientação está sendo considerada para alinhar, lembrando que é possível alternar qual é o eixo principal e secundário pelo comando *flex-direction*.

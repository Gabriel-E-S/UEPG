# Prova 1 de Dev web - Gabriel do Espírito Santo -- Questão 2

## Questão 1 - O que é DOM e para o que ele é usado?

DOM - Document Object Manipulation

O DOM é uma forma de representar a estrutura das páginas web, como uma estrutura de árvore, com elementos pais e filhos, sendo possível analisar, alterar e criar novos elementos a partir da manipulação dessa estrutura por meio de linguagens de programação como o JavaScript, além de conseguir deixar as páginas mais responsivas e interativas.

Elementos em uma mesma hierarquia são considerados irmãos da árvore, e a raiz geralmente é o body.

## Questão 2 - Como é possível alterar elementos já existente em uma página por meio do uso de JavaScript?

Por meio da manipulação do DOM da página. é possível recuperar o elemento por meio da função document.querySelectorAll() ou document.querySelector() ou das outras específicas como o document.getElementById(). Logo após isso, é possível mudar o conteúdo textual do elemento recuperado utilizando propriedades como .textContent e .innerHTML. e para alterar a questão da estilização é possível modificar propriedades do CSS diretamente ou fazer isso de forma mais elegante adicionando e retirando classes por meio de comandos deerivados da Lista de classes.

## Questão 3 - Qual a principal diferença entre os comandos getElementById e QuerySelector?

A principal diferença entre os dois é que o comando getElementById é mais específico e  busca e retorna somente elementos dados um id de busca, enquanto que o querySelector é uma função mais genérica, sendo possível retornar elementos de HTML como por exemplo a tag h1, elementos contidos em classes e também permite buscar elementos pelo ID.

QuerySelector() retorna o primeiro elemento encontrado como o indicador passado como parâmetro, sua variação querySelectorAll() retorna uma lista com todos os elementos encontrados com tal identificador.

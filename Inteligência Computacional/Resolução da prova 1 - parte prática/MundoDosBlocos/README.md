# Projeto: O Mundo dos Blocos (AIMA-Java)

Este projeto implementa a resolução do clássico problema de Inteligência Artificial **"Mundo dos Blocos" (Blocks World)**, utilizando a biblioteca **AIMA-Java** (Artificial Intelligence: A Modern Approach). 

O algoritmo utilizado para encontrar o plano de ações é a **Busca em Largura** (*Breadth-First Search*) acoplada a uma **Busca em Grafo** (*GraphSearch*) para otimização de memória e prevenção de loops infinitos.

## Estrutura de Arquivos

A solução foi modularizada seguindo as práticas do framework AIMA e é composta por 5 classes:

1. `BAction.java`: Define as ações possíveis do braço robótico (`empilha` e `desempilha`).
2. `EBlocos.java`: Representa o estado do mundo (a mesa e as pilhas de blocos).
3. `BFunctions.java`: Contém as funções de transição (geração de ações viáveis e o estado resultante com *Deep Copy*) e a função de custo.
4. `GTBlocos.java`: Implementa o Teste de Objetivo (*Goal Test*).
5. `RunDemoBlocos.java`: Classe principal que configura o estado inicial, inicializa o problema genérico e executa a busca.

## Como Integrar e Executar

Como este projeto utiliza a base do AIMA fornecida em sala, siga os passos abaixo para testar o código no seu ambiente:

### 1. Integração dos Arquivos
O pacote padrão destas classes é definido como `MundoDosBlocos`. 
1. Navegue até o diretório fonte (`src` ou `src/main/java`) do seu projeto AIMA base.
2. Crie uma nova pasta chamada `MundoDosBlocos`.
3. Arraste as 5 classes listadas acima para dentro desta pasta.

### 2. Execução

Execute a classe `RunDemoBlocos.java`. O método `main` irá instanciar o problema e disparar a busca. 
* O plano de ações será impresso diretamente no console.

## Como testar diferentes Estados Iniciais

Por padrão, a classe principal configura o "Pior Caso" ou um cenário bagunçado para forçar o algoritmo a trabalhar. Para testar outras configurações, edite o método `runBreadthFirstSearch()` na classe `RunDemoBlocos.java`:

```java
// Exemplo de como montar a mesa alterando o array interno:
List<List<String>> arranjoInicial = Arrays.asList(
    Arrays.asList("A", "C", "B"), // B no topo, C no meio, A na base
    Arrays.asList("E", "D"),      // D no topo, E na base
    Arrays.asList("F")            // F solto na mesa
);
package MundoDosBlocos;

import java.util.List;
import java.util.Arrays;
import java.util.Collections;
import java.util.Optional;

import aima.core.search.agent.SearchAgent;
import aima.core.search.framework.SearchForActions;
import aima.core.search.framework.problem.GeneralProblem;
import aima.core.search.framework.problem.Problem;
import aima.core.search.uninformed.BreadthFirstSearch;
import aima.core.search.framework.qsearch.GraphSearch;

public class RunDemoBlocos {
    
    public void run() {
        this.runBreadthFirstSearch();
    }

    private void runBreadthFirstSearch() {
        
        // Estado Inicial: Blocos A, B e C soltos na mesa
        // Estado Inicial Complexo:
    // Estado Inicial Complexo (Bagunçado):
List<List<String>> arranjoInicial = Arrays.asList(
    Arrays.asList("A", "C", "B"), // B no topo, impedindo acesso ao C
    Arrays.asList("E", "D"),      // D no topo
    Arrays.asList("F")            // F sozinho
);
    
    EBlocos inicial = new EBlocos(arranjoInicial);  

        Problem<EBlocos, BAction> problem;  
        problem = new GeneralProblem<>(
                inicial,
                BFunctions::getActions,   
                BFunctions::getResult,    
                BFunctions::testGoal      
        );

        // O Mundo dos Blocos DEVE usar Busca em Grafo (GraphSearch) para não entrar em loop infinito
        SearchForActions<EBlocos, BAction> search = new BreadthFirstSearch<>(new GraphSearch());
        
        System.out.println("Iniciando a busca do Mundo dos Blocos");
        Optional<List<BAction>> actions = search.findActions(problem);
        this.printActions(actions);
    }
  
    private void printActions(Optional<List<BAction>> actions) {
        if (actions.isPresent()) {
            List<BAction> acList = actions.get();
            System.out.println("\nPLANO DE ACOES ENCONTRADO");
            for (int i = 0; i < acList.size(); i++) {
                String act = acList.get(i).getName();
                System.out.println((i + 1) + ". " + act);
            }
        } else {
            System.out.println("Nenhuma solucao encontrada.");
        }
    }

    public static void main(String[] args) {
        RunDemoBlocos demo = new RunDemoBlocos();
        demo.run();
    }
}
    
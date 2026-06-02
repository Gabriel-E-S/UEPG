package MundoDosBlocos;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import aima.core.search.framework.problem.StepCostFunction;

public class BFunctions {

    public static StepCostFunction<EBlocos, BAction> getBCostFunction() {
        return new BStepCostFunctionImpl();        
    }
    
    public static List<BAction> getActions(EBlocos state) {
        List<BAction> actions = new ArrayList<>(); 
        List<String> topos = new ArrayList<>();

        // Identifica quem está no topo (livre)
        for (List<String> pilha : state.getPilhas()) {
            String topo = pilha.get(pilha.size() - 1);
            topos.add(topo);

            // AÇÃO 1: Desempilhar (só se não estiver na mesa)
            if (pilha.size() > 1) {
                actions.add(new BAction(BAction.DESEMPILHA, topo, null));
            }
        }

        // AÇÃO 2: Empilhar (qualquer topo sobre outro topo diferente)
        for (String b1 : topos) {
            for (String b2 : topos) {
                if (!b1.equals(b2)) {
                    actions.add(new BAction(BAction.EMPILHA, b1, b2));
                }
            }
        }
        return actions;
    }
    
    public static EBlocos getResult(EBlocos e, BAction ac) {
        // Deep copy do estado atual
        List<List<String>> novasPilhas = new ArrayList<>();
        for (List<String> pilha : e.getPilhas()) {
            novasPilhas.add(new ArrayList<>(pilha));
        }

        if (ac.getTipo().equals(BAction.DESEMPILHA)) {
            String bloco = ac.getB1();
            for (List<String> pilha : novasPilhas) {
                if (!pilha.isEmpty() && pilha.get(pilha.size() - 1).equals(bloco)) {
                    pilha.remove(pilha.size() - 1);
                    break;
                }
            }
            // Vai para a mesa
            novasPilhas.add(new ArrayList<>(Collections.singletonList(bloco)));

        } else if (ac.getTipo().equals(BAction.EMPILHA)) {
            String b1 = ac.getB1();
            String b2 = ac.getB2();

            // Tira b1 de onde ele estiver
            for (List<String> pilha : novasPilhas) {
                if (!pilha.isEmpty() && pilha.get(pilha.size() - 1).equals(b1)) {
                    pilha.remove(pilha.size() - 1);
                    break;
                }
            }
            // Coloca b1 em cima de b2
            for (List<String> pilha : novasPilhas) {
                if (!pilha.isEmpty() && pilha.get(pilha.size() - 1).equals(b2)) {
                    pilha.add(b1);
                    break;
                }
            }
        }
        return new EBlocos(novasPilhas);
    }
  
    public static boolean testGoal(EBlocos e) {
        // Define o objetivo aqui: A sobre B, e B sobre C
        List<String[]> objetivo = new ArrayList<>();
        objetivo.add(new String[]{"A", "B"}); 
        objetivo.add(new String[]{"B", "C"}); 
        
        GTBlocos gt = new GTBlocos(objetivo);
        return gt.test(e);
    }
    
    private static class BStepCostFunctionImpl implements StepCostFunction<EBlocos, BAction> {
        private BStepCostFunctionImpl() {}

        @Override
        public double applyAsDouble(EBlocos state, BAction action, EBlocos statePrimed) {
            return 1.0; // Qualquer movimento do braço custa 1
        }
    }
}
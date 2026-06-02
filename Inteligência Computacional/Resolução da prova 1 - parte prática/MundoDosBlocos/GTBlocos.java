package MundoDosBlocos;

import aima.core.search.framework.problem.GoalTest;
import java.util.List;

public class GTBlocos implements GoalTest {
    
    private List<String[]> condicoesOn; // Pares de blocos alvo
    
    public GTBlocos(List<String[]> condicoesOn) {
        this.condicoesOn = condicoesOn;
    }
    
    @Override
    public boolean test(Object state) {
        EBlocos blocos = (EBlocos) state;

        // Verifica se TODAS as condições exigidas (ex: A sobre B) foram atendidas
        for (String[] condicao : condicoesOn) {
            String blocoCima = condicao[0];
            String blocoBaixo = condicao[1];
            boolean encontrou = false;

            for (List<String> pilha : blocos.getPilhas()) {
                int index = pilha.indexOf(blocoBaixo);
                // Se achou o bloco de baixo, verifica se o próximo (em cima) é o que queremos
                if (index != -1 && index + 1 < pilha.size() && pilha.get(index + 1).equals(blocoCima)) {
                    encontrou = true;
                    break;
                }
            }
            if (!encontrou) return false;
        }
        return true;
    }
}

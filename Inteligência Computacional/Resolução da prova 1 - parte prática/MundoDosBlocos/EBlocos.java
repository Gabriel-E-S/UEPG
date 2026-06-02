package MundoDosBlocos;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class EBlocos {

    private List<List<String>> pilhas;

    // Construtor
    public EBlocos(List<List<String>> pilhasIniciais) {
        this.pilhas = new ArrayList<>();
        for (List<String> pilha : pilhasIniciais) {
            if (!pilha.isEmpty()) {
                this.pilhas.add(new ArrayList<>(pilha)); // Deep copy
            }
        }
        // Canonicaliza: ordena as pilhas por ordem alfabética para não diferenciar a ordem na mesa
        this.pilhas.sort((p1, p2) -> p1.toString().compareTo(p2.toString()));
    }

    public List<List<String>> getPilhas() {
        return this.pilhas;
    }

    @Override
    public String toString() {
        return pilhas.toString();
    }

    // Essencial para o algoritmo não entrar em Loop Infinito
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        EBlocos other = (EBlocos) obj;
        return Objects.equals(this.pilhas, other.pilhas);
    }

    @Override
    public int hashCode() {
        return Objects.hash(pilhas);
    }
}
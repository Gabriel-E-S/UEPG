package MundoDosBlocos;

import aima.core.agent.impl.DynamicAction;

public class BAction extends DynamicAction {
    
    public static final String DESEMPILHA = "desempilha";
    public static final String EMPILHA = "empilha";

    private String tipo;
    private String b1;
    private String b2;

    public BAction(String tipo, String b1, String b2) {
        super(tipo + "(" + b1 + (b2 != null ? "," + b2 : "") + ")");
        this.tipo = tipo;
        this.b1 = b1;
        this.b2 = b2;
    }

    public String getTipo() { return tipo; }
    public String getB1() { return b1; }
    public String getB2() { return b2; }
}

public class Principal {

    public static void main(String args[]) {
        Produto vetorDeProdutos[] = new Produto[3];
        
        vetorDeProdutos[0] = new Produto("Arroz",12,2.0);
        vetorDeProdutos[1] = new Produto("Feijao",2,1.0);
        
        vetorDeProdutos[0].comprar(2);
        System.out.println(vetorDeProdutos[1].imprimir());
    }
}

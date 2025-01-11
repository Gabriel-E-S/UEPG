public class Principal {

  public static void main(String[] args) {

    Produto vetorDeProdutos[]   = new Produto[2]; // Criando o vetor de produtos.

    Data validadeDoNescau = new Data(12,02,2028); // Criando as datas para os construtores.

    Data validadeDoToddynho = new Data(15,4,2027);

    vetorDeProdutos[0] = new Produto("Lata de Nescau",2,10,validadeDoNescau);
    vetorDeProdutos[1] = new Produto("Garrafa de Toddynho",validadeDoToddynho);

    System.out.println("\nAntes das modificacoes\n");
    System.out.println(vetorDeProdutos[0]);
    System.out.println(vetorDeProdutos[1]);

    vetorDeProdutos[0].setValidade(10,1,2026); // Fazendo as modificacões.

    Data validadeNova = new Data(11,11,2026);

    vetorDeProdutos[1].setValidade(validadeNova);

    System.out.println("\nDepois das modificacoes\n");
    System.out.println(vetorDeProdutos[0]);
    System.out.println(vetorDeProdutos[1]);

  }
}

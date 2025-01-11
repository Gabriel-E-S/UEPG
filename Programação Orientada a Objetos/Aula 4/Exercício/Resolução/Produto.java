public class Produto{

  // Atributos.
  
  private String nome;
  private double preco;
  private int quantidade;
  private Data validade;

  // Construtores.
  
  public Produto(String nome, double preco, int quantidade, Data validade) {
    this.nome = nome;
    this.preco = preco;
    this.quantidade = quantidade;
    this.validade = validade;
  }
  public Produto(String nome, double preco, Data validade) {
    this.nome = nome;
    this.preco = preco;   
    this.validade = validade;
  }
  public Produto(String nome,Data validade) {
    this.nome = nome;
    this.validade = validade;
  }

  // Métodos set.
  
  public void setNome(String nome) {
    this.nome = nome;
  }
  public void setPreco(double preco){
    this.preco = preco;
  }
  public void setQuantidade(int quantidade){
    this.quantidade = quantidade;
  }
  public void setValidade(int dia, int mes, int ano){
    validade = new Data(dia,mes,ano);
  }
  public void setValidade(Data validade){
    this.validade = validade;
  }

  // Métodos get
  
  public String getNome() {
    return nome;
  }
  public double getPreco(){
    return preco;
  }
  public int getQuantidade(){
    return quantidade;
  }
  
  // Outros métodos.
  
  public void vender(int quantidade){

    if(this.quantidade >= quantidade){
      this.quantidade = this.quantidade - quantidade;
    }
    else{
      System.out.println("NAO FOI POSSIVEL CONCLUIR A VENDA, QUANTIDADE INSUFICIENTE\n");
    }
  }

  public void comprar(int quantidade){
    if(quantidade > 0){
      this.quantidade = this.quantidade + quantidade ;
    }
  }

  public String toString(){
    String aux;

    aux = "PRODUTO: " + nome + "\nPRECO = " + preco + "\nQUANTIDADE = " + quantidade + "\nVALIDADE = " + validade + "\n" ;

    return aux;
  }



  






}

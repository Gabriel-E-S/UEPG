public class Produto{
    
    // atributos privados
    
    private String nome;
    private int quantidade;
    private double preco;
    
    // construtores
    
    public Produto(String nome,int quantidade,double preco){
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;
    }
    
    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }
    
    // métodos get e set para todos os atributos
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }
    
    // método imprimir
    
    public String imprimir() {
        return "Produto{" + "nome=" + nome + ", quantidade=" + quantidade + ", preco=" + preco + '}';
    }
    
    // método comprar
    
    public void vender(int qtd){
        if(qtd > 0 && qtd <= this.quantidade){
            this.quantidade = this.quantidade - qtd;
        }
    }
    
    // método vender
    
    public void comprar(int qtd){
        if(qtd > 0){
            this.quantidade = this.quantidade + qtd;
        }
    } 
}
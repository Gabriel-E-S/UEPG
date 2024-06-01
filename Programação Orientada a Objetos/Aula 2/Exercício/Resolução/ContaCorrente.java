public class ContaCorrente{
   
   // atributos

   private String nomeDoCliente ;
   private int numeroDaConta ;
   private short numeroDaAgencia ;   
   
   private double saldo ;
   private double limite ;
   
   // metodos set
   
   public void setNomedocliente(String nomeDoCliente){
      this.nomeDoCliente = nomeDoCliente;
   }
   public void setNumeroDaConta(int numeroDaConta){
      if (numeroDaConta > 0)
         this.numeroDaConta = numeroDaConta ;
      else System.out.println("Número inválido") ;
   }
   public void setNumeroDaAgencia(short numeroDaAgencia){
      this.numeroDaAgencia = numeroDaAgencia ;
   }
   
   public void setSaldo(double saldo){
      this.saldo = saldo ;
   }
   public void setLimite(double limite){
      this.limite = limite ;
   }
   
   // metodos get
   
   public String getNomeDoCliente (){
      return nomeDoCliente;
   }
   public int getNumeroDaConta(){
      return numeroDaConta ;
   }
   public short getNumeroDaAgencia(){
      return numeroDaAgencia ;
   }
   public double getSaldo (){
      return saldo;
   }
   public double getLmite(){
      return limite ;
   }
   
   //métodos construtores
   
   public ContaCorrente(String nomeDoCliente, int numeroDaConta, short numeroDaAgencia, double saldo, double limite){
      this.nomeDoCliente = nomeDoCliente ;
      this.numeroDaAgencia = numeroDaAgencia;
      this.numeroDaConta = numeroDaConta ;
      this.saldo = saldo ;
      this. limite = limite ;
   } 
   public ContaCorrente(String nomeDoCliente, int numeroDaConta, short numeroDaAgencia, double saldo){
      this.nomeDoCliente = nomeDoCliente ;
      this.numeroDaAgencia = numeroDaAgencia;
      this.numeroDaConta = numeroDaConta ;
      this.saldo = saldo ;
   } 
   public ContaCorrente(String nomeDoCliente, int numeroDaConta, short numeroDaAgencia){
      this.nomeDoCliente = nomeDoCliente ;
      this.numeroDaAgencia = numeroDaAgencia;
      this.numeroDaConta = numeroDaConta ;
   } 

   // metodos normais
   
   public void atualizar (double saldo, double limite){
      this.saldo = saldo ;
      this.limite = limite ;
   }
   
   public void atualizar (String nomeDoCliente, double limite, short numeroDaAgencia){
      this.nomeDoCliente = nomeDoCliente ;
      this.limite = limite ;
      this.numeroDaAgencia = numeroDaAgencia ;
   }
   
   
   public void sacar(double valor){
   
         if(valor > 0 && valor <= saldo){
            saldo = saldo - valor ;
         }
         else System.out.println("Valor muito grande, saldo indisponível") ;
   }
   
   public void depositar(double valor){
      
         if(valor > 0)
            saldo = saldo + valor ;     
   }
   
   public void imprimir(){
      System.out.println("\nNome:"+nomeDoCliente) ;
      System.out.println("Numero da conta:"+numeroDaConta);
      System.out.println("Numero da agencia:"+numeroDaAgencia);
      System.out.println("Saldo -->  R$ " + saldo) ;
      System.out.println("Limite --> R$ " + limite) ;
   }
}
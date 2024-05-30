public class ContaCorrente{

   public String nomeDoCliente ;
   public int numeroDaConta ;
   public int numeroDaAgencia ;
   
   private double saldo ;

   public void sacar(double valor){
        if(valor <= saldo && valor > 0){
            saldo = saldo - valor ;
        }
        else{
            System.out.println("valor insuficiente!");
        }
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
    }


}
   
   
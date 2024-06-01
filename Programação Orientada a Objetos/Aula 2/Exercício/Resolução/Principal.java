public class Principal {
   public static void main(String args[]){
   
      ContaCorrente conta1, conta2, conta3;
      
      // criando os objetos
      
      conta1 = new ContaCorrente("Gabriel",400,(short)30);
      conta2 = new ContaCorrente("Irineu",150,(short)40,1000) ;
      conta3 = new ContaCorrente("Joaozinho",100,(short)40,1500,2000);
      
      System.out.println("\n**************** Antes das modificacoes ****************\n\n") ;
      
      conta1.imprimir();
      conta2.imprimir();
      conta3.imprimir();
      
      // operações bancarias
      
      conta1.depositar(1000);
      conta1.sacar(100);
      conta1.setLimite(1000) ;
      
      conta2.depositar(200);
      conta2.atualizar("Pedro Alvares Cabral",400,(short)30);
      conta3.atualizar(10000,50000);

      
      System.out.println("\n\n**************** Depois das modificacoes ****************\n") ;
      conta1.imprimir();
      conta2.imprimir();
      conta3.imprimir();
   }
}
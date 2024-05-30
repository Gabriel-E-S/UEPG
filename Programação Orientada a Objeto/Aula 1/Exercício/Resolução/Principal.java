public class Principal {
    public static void main(String args[]){
    
        ContaCorrente conta1,conta2,conta3 ;
       
        conta1 = new ContaCorrente();
        conta2 = new ContaCorrente() ;
        conta3 = new ContaCorrente();
       
        conta1.nomeDoCliente = "Gabriel" ;
        conta2.nomeDoCliente = "José";
        conta3.nomeDoCliente = "Paula";

        conta1.numeroDaAgencia = 123;
        conta2.numeroDaAgencia = 1234;
        conta3.numeroDaAgencia = 1235;

        conta1.numeroDaConta = 123;
        conta2.numeroDaConta = 1234;
        conta3.numeroDaConta = 1235;

       System.out.println("\n**************** Antes das modificacoes ****************\n\n") ;
       conta1.imprimir();
       conta2.imprimir();
       conta3.imprimir();
       
       // operações bancarias
       
       conta1.depositar(1000);
       conta1.sacar(100);
       
       conta2.depositar(200);

       System.out.println("\n\n**************** Depois das modificacoes ****************\n") ;
       conta1.imprimir();
       conta2.imprimir();
       conta3.imprimir();
       
 
      
    }
}
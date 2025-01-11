public class Funcionario extends Pessoa {

   // Atributos.

   private String registro ;
   private double salario ;
   
   // Construtores.
   
   public Funcionario(String nome, String telefone, Data nascimento, String registro, double salario){
        super(nome,telefone,nascimento) ;
        this.registro = registro ;
        this.salario = salario ;
   }
   
   public Funcionario(String nome, Data nascimento, String registro, double salario){
        super(nome,nascimento) ;
        this.registro = registro ;
        this.salario = salario ;
   }
   
   // Métodos get.
   
   public final double getSalario(){
      return salario ;
   }
   public String getRegistro(){
      return registro ;
   }
   
   // Métodos set.
   
   public void setSalario(double salario){
      if(salario > 0){
         this.salario = salario ;
         System.out.println("SALARIO ATUALIZADO!!") ;
      }
      else{
         System.out.println("SALARIO INVALIDO!!") ;
      }
   }
   public void setRegistro(String registro){
      this.registro = registro;
      System.out.println("REGISTRO ATUALIZADO!!") ;
   }
   
   // Método to string, foi utilizado o toString() da classe superior para compor ele.
   
   public String toString(){
      
      String aux ;
      
      aux = super.toString() + "\nREGISTRO = " + registro + "\nSALARIO = " + salario ;
      
      return aux ;
      
   }

   // Método.
   
   public double bonificar(){
      return (salario * 0.10) ;
   }
}

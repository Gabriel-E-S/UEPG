public class Chefe extends Funcionario{

   // Atributos.
   
   private String cargo ;
   
   // Construtores.
   
   public Chefe(String nome, String telefone, Data nascimento, String registro, double salario, String cargo){
      super(nome,telefone,nascimento,registro,salario);
      this.cargo = cargo ;      
   }
   
   public Chefe(String nome, Data nascimento, String registro, double salario, String cargo){
      super(nome,nascimento,registro,salario);
      this.cargo = cargo ;      
   }
   
   // Método set.
   
   public void setCargo(String cargo){
      this.cargo = cargo ;
   }
   
   // Método get.
   
   public String getCargo(){
      return cargo ;
   }
   
   // Métodos.
   
   public double bonificar(){
      return (getSalario() * 0.20);
   }
      
   // Método toString().
   
   public String toString(){
      
      String aux ;
      
      aux = super.toString() + "\nCARGO = " + cargo ;
      
      return aux ;
      
   }
}

public class Aluno extends Pessoa{

   // Atributos

   private String ra ;
      
   // Construtores
   
   public Aluno(String nome, String telefone, Data nascimento, String ra){
      super(nome,telefone,nascimento) ;
      this.ra = ra ;
   }
   
   public Aluno(String nome, Data nascimento, String ra){
      super(nome,nascimento) ;
      this.ra = ra ;
   }
   
   // Métodos set
   
   public void setRa(String ra){
      this.ra = ra ;
   }
   
   // metodos get
   
   public String getRa(){
      return ra;
   }
   
   // metodo toString
   
   public String toString(){
      String aux ;
      
      aux = super.toString() + "\nRA = " + ra ;
      
      return aux ;
   }
}

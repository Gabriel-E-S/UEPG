public class Pessoa{

   // Atributos

   private String nome ;
   private String telefone ;
   private Data nascimento ;
      
   // Métodos construtores
   
   public Pessoa (String nome,String telefone, Data nascimento){
      this.nome = nome ;
      this.telefone = telefone ;
      this.nascimento = nascimento ;
  
   }
   public Pessoa (String nome, Data nascimento){
      this.nome = nome ;
      this.nascimento = nascimento ;
      telefone = "NAO CADASTRADO" ;
  
   }
   
   // Métodos set
   
   public void setNome(String nome){
      this.nome = nome ;
   }
   public void setTelefone(String telefone){
      this.telefone = telefone ;
   }
   
   public void setNascimento(Data nascimento){
      this.nascimento = nascimento ;
   }
   
   // Métodos get 
   
   public String getNome(){
      return nome ;
   }
   public String getTelefone(){
      return telefone ;
   }
   
   public Data getNascimento(){
      return nascimento;
   }
   
   // Método toString
   
   public String toString(){
      String aux ;
      
      aux = "\n\nNOME = " + nome + "\nTELEFONE = " + telefone + "\nNASCIMENTO = " + nascimento ;
      return aux;
   
   }
}

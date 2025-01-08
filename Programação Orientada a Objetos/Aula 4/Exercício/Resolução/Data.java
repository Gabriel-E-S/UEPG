public class Data{


   // Atributos

   private int dia ;
   private int mes ;
   private int ano ;
   
   // Método construtor
   
   public Data(int dia, int mes, int ano){
      this.dia = dia ;
      this.mes = mes ;
      this.ano = ano ;
   }
         
   // Métodos set
   
   public void setDia(int dia){
      if(dia > 0 && dia <= 31){
            this.dia = dia ;
            System.out.println("Dia atualizado") ;
      }
      else{
         System.out.println("Dia invalido") ;
      }
   }
   
   public void setMes(int mes){
   
      if(mes > 0 && mes <=12){
         this.mes = mes ;
         System.out.println("Mes atualizado") ;

      }
      else{
         System.out.println("Mes invalido") ;
      }

   
   }
   public void setAno(int ano){
   
      if(ano > 1950){
         this.ano = ano ;
         System.out.println("Ano atualizado") ;

      }
      else{
         System.out.println("Ano invalido") ;
      }
   
   }

   // Métodos get
   
   public int getDia(){
      return dia;
   }
   public int getMes(){
      return mes;
   }
   public int getAno(){
      return ano;
   }

   // Método toString
   
   public String toString(){
      String aux ;
      
      aux = dia + "/" + mes + "/" + ano ;
      return aux ;
   }
}

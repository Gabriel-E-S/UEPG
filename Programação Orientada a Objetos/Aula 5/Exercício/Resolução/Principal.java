public class Principal{

  public static void main(String[] args) {

    Data dia1 = new Data(25,12,2000);
    Data dia2 = new Data(1,11,1990);

    Aluno aluno1 = new Aluno("Jose","12345",dia1,"4321");

    Funcionario funcionario1 = new Funcionario("Maria","1345",dia2,"4421",200);
    
    Chefe chefe1 = new Chefe("Mario","13435",dia2,"2421",200,"Chefe de departamento");

    System.out.println(aluno1);

    System.out.println(funcionario1);
    System.out.println("Bonificação = " + funcionario1.bonificar() + "\n");
    System.out.println(chefe1);
    System.out.println("Bonificação = " + chefe1.bonificar() + "\n");
    
  }
}

class Main {
  public static void main(String[] args) {
    Projeto p1 = new Projeto("Projeto de delivery de pizzaria", "Luís", 85);
    Projeto p2 = new Projeto("Site de alugar carros", "Caio", 102, "Dely", "Aprimorar interface");
    /*NORMAL*/
    p1.addTarefa("Front-end do site", "Ícaro Baliza");
    
    /*SOBRECARGA*/
    p1.addTarefa("Mobile", "Felipe");
       System.out.println(p1.estaFinalizado());
    /*verificado a veracidade do metodo finalizar tareda*/
    p1.finalizarTarefa(100, "Front-end do site");
    p1.finalizarTarefa(220, "Mobile");

    
    p2.addTarefa("Fixar bugs", "Luísa");
    p2.finalizarTarefa(100, "Fixar bugs");
    
   System.out.println(p1.estaFinalizado());
  }
}

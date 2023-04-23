import java.util.ArrayList;
class Main {
  public static void main(String[] args) {
      ArrayList<Personagem> personagens = new ArrayList<Personagem>();
    
      Personagem p1 = new Personagem("Reynan", 15, 50);
      Personagem p2 = new Personagem("Naldo", 4, 10);
      Personagem p3 = new Personagem("Izuha", 18, 544);

      personagens.add(p1);
      personagens.add(p2);
      personagens.add(p3);
      p1.mostrarStatus();
      p1.atacar("Naldo", "VENTO MORTAL");
      for (Personagem p : personagens) {
        System.out.println(p.getNome() + " " + p.getForca() + " " + p.getNivel());
    }
  }
}
class Main {
  public static void main(String[] args) {
    Lutador l1 = new Lutador("Pretty boy", "Franca", 31, 1.75f, 68.9f, "A", 11, 2, 1);
    Lutador l2 = new Lutador("PutsScript", "Brazil", 21, 1.32f, 38.9f, "A", 41, 22, 13);
    Lutador l3 = new Lutador("ararr", "Alemanha", 51, 1.55f, 48.9f, "A", 12, 24, 72);
  

    Luta UEC1 = new Luta();
    Luta UEC2 = new Luta();
    UEC1.marcarLuta(l1, l2);
    UEC1.lutar();
    l1.status();
    l2.status();
    /*
    UEC2.marcarlutar(l4, l3);
    UEC2.lutar();*/
    /*
   Lutador l[] = new Lutador[3];

    l[0] = new Lutador("Pretty boy", "Franca", 31, 1.75f, 68.9f, "A", 11, 2, 1);
    l[1] = new Lutador("PutsScript", "Brazil", 21, 1.32f, 38.9f, "A", 41, 22, 13);
    l[2] = new Lutador("ararr", "Alemanha", 51, 1.55f, 48.9f, "A", 12, 24, 72);

    Luta UEC1 = new Luta();
    UEC1.marcarLuta(l[0], l[1]);
    UEC1.lutar();
    l[0].status();
    l[1].status();*/
  }
}

import java.util.Random;
import java.util.ArrayList;

public class Luta{
  private Lutador desafiado;
  private Lutador desafiante;
  private int rounds;
  private boolean aprovada;
  private ArrayList<Lutador> lutadores = new ArrayList<>();
  
  /*------ ADICIONAR UM LUTADOR DE OUTRA FORMA, ATRAVES D EUM METODO ------*/
  public boolean addLutador(String nome, String nacionalidade, int idade,  float altura,  float peso, String categoria, int vitorias, int derrotas, int empates){
    if(nome.equals(null) || nacionalidade.equals(null) || categoria.equals(null)){
      return false;
    }else{
      this.lutadores.add(new Lutador(nome, nacionalidade, idade, altura, peso, categoria, vitorias, derrotas, empates));
      return true;
    }
  }
    
  
  public void marcarLuta(Lutador l1, Lutador l2){
    if(l1.getCategoria().equals(l2.getCategoria()) && l1 != l2){
      this.aprovada = true;
      this.desafiado = l1;
      this.desafiante = l2;
    }else{
      this.aprovada = false;
      this.desafiado = null;
      this.desafiante = null;
    }
  }

  public void lutar(){
    if(this.aprovada){
      System.out.println("### DESAFIADO ###");
      this.desafiado.apresentar();
      System.out.println("### DESAFIANTE ###");
      this.desafiante.apresentar();

      Random aleatorio = new Random();
      int vencedor = aleatorio.nextInt(3);
      switch(vencedor){
        case 0: //empate
          System.out.println("EMPATOU!");
          this.desafiado.empatarLuta();
          this.desafiante.empatarLuta();
          break;
          case 1: //
          System.out.println("VITORIA DO " + desafiado.getNome());
          this.desafiado.ganharLuta();
          this.desafiante.perderLuta();
          break;
          case 2: //
          System.out.println("VITORIA DO " + desafiante.getNome());
          this.desafiado.perderLuta();
          this.desafiante.ganharLuta();
          break;
      }
    }
  }

  /*------ METODOS GET E SET ------*/
public Lutador getDesafiado() {
	return desafiado;
}

public void setDesafiado(Lutador desafiado) {
	this.desafiado = desafiado;
}

public Lutador getDesafiante() {
	return desafiante;
}

public void setDesafiante(Lutador desafiante) {
	this.desafiante = desafiante;
}

public int getRounds() {
	return rounds;
}

public void setRounds(int rounds) {
	this.rounds = rounds;
}

public boolean isAprovada() {
	return aprovada;
}

public void setAprovada(boolean aprovada) {
	this.aprovada = aprovada;
}

  
  

}

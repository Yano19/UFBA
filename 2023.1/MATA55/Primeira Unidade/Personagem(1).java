import java.util.Random;
import java.util.ArrayList;

public class Personagem{
  private String nome;
  private int nivel = 0;
  private int forca = 0;
  public ArrayList<Personagem> personagens;
  
  public Personagem(String nome, int nivel, int forca, ArrayList<Personagem> personagens){
    this.nome = nome;
    this.nivel = nivel;
    this.forca = forca;
    this.personagens = personagens;
  }

  public Personagem(String nome, int nivel, int forca){
    this.nome = nome;
    this.nivel = nivel;
    this.forca = forca;
  }
  public String getNome() {
	return nome;
}

public void setNome(String nome) {
	this.nome = nome;
}

public int getNivel() {
	return nivel;
}

public void setNivel(int nivel) {
	this.nivel = nivel;
}

public int getForca() {
	return forca;
}

public ArrayList<Personagem> getPersonagens() {
	return personagens;
}
public void setPersonagens(ArrayList<Personagem> personagens) {
	this.personagens = personagens;
}
  
public void setForca(int forca) {
	this.forca = forca;
}

    /*adicionar Personagem*/
  public boolean addPersonagem(String nome, int nivel, int forca){
    if(nome == null){
      return false;
    }else{
      this.personagens.add(new Personagem(nome, nivel, forca));
      return true;
    }
  }
  
//void = nao retorna nada
  public void mostrarStatus(){
    System.out.println("Personagem: " + this.nome + " tem " + this.forca + " de forca e " + this.nivel + " de nivel");
  }

  public void atacar(String alvo, String habilidade){
    if(habilidade.length() == 0){
      System.out.println("Personagem: " + this.nome + " Atacou o " + alvo + " e causou " + this.forca + " de dano");
    } else{
      System.out.println("Personagem: " + this.nome + " usou a habilidade " + habilidade);
    }
  }
  
  public int calcularDano(){
    Random gerador = new Random();
    int dado20Faces = 1 + gerador.nextInt(19);
    int dano = this.forca + dado20Faces;
    return dano;
  }
}


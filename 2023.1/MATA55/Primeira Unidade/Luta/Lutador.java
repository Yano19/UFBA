public class Lutador{
  private String nome;
  private String nacionalidade;
  private int idade;
  private float altura;
  private float peso;
  private String categoria;
  private int vitorias, derrotas, empates;

  /*---------- CONSTRUTOR -------*/
  public Lutador(String nome, String nacionalidade, int idade,  float altura,  float peso, String categoria, int vitorias, int derrotas, int empates){
    this.nome = nome;
    this.nacionalidade = nacionalidade;
    this.idade = idade;
    this.altura = altura;
    this.peso = peso;
    this.categoria = categoria;
    this.vitorias = vitorias;
    this.derrotas = derrotas;
    this.empates = empates;
  }
  
  public String getNome() {
	return nome;
}

public void setNome(String nome) {
	this.nome = nome;
}

public String getNacionalidade() {
	return nacionalidade;
}

public void setNacionalidade(String nacionalidade) {
	this.nacionalidade = nacionalidade;
}

public int getIdade() {
	return idade;
}

public void setIdade(int idade) {
	this.idade = idade;
}

public float getAltura() {
	return altura;
}

public void setAltura(float altura) {
	this.altura = altura;
}

public float getPeso() {
	return peso;
}

public void setPeso(float peso) {
	this.peso = peso;
}

public String getCategoria() {
	return categoria;
}

public void setCategoria(String categoria) {
	this.categoria = categoria;
}

public int getVitorias() {
	return vitorias;
}

public void setVitorias(int vitorias) {
	this.vitorias = vitorias;
}

public int getDerrotas() {
	return derrotas;
}

public void setDerrotas(int derrotas) {
	this.derrotas = derrotas;
}

public int getEmpates() {
	return empates;
}

public void setEmpates(int empates) {
	this.empates = empates;
}

  
public void apresentar(){
    System.out.println("----------------------------------------");
    System.out.println("CHEGOU A HORA DE APRESENTAR O lutador " + this.getNome());
    System.out.println("Diretamente de " + this.getNacionalidade());
    System.out.println("com " + this.getIdade() + " anos e " + this.getAltura() + " a");
    System.out.println("pesando " + this.getPeso() + " kg");
    System.out.println(this.getVitorias() + " Vitorias");
    System.out.println(this.getDerrotas() + " Derrotas");
   System.out.println(this.getDerrotas() + " Empates");
  }

  public void status(){
    System.out.println(this.getNome() + " é um peso " + this.getCategoria());
    System.out.println("Ganhou " + this.getVitorias() + " vezes");
    System.out.println("Perdeu " + this.getDerrotas() + " vezes");
    System.out.println("Empatou " + this.getEmpates() + " vezes");
  }

  public void ganharLuta(){
    this.setVitorias(this.getVitorias() + 1); /*somando todas as vitorias que ele ja teve*/
  }

  public void perderLuta(){
    this.setDerrotas(this.getDerrotas() + 1);
  }

  public void empatarLuta(){
    this.setEmpates(this.getEmpates() + 1);
  }
}

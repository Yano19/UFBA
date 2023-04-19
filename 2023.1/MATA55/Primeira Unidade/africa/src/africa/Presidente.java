package africa;


import java.util.ArrayList;
import java.util.List;

public class Presidente {
	private String nome;
	private String sobrenome;
	private int idade;
	private List<Filhoo> filhos = new ArrayList()<>;
	
	
	public Presidente(String nome, String sobrenome, int idade, Filhoo filhos) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.idade = idade;
		this.filhos = new ArrayList<>();
	}
		
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getSobrenome() {
		return sobrenome;
	}
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	public int getIdade() {
		return idade;
	}
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
	/*METODO PARA ADICIONAR UM NOVO FILHO*/
	public void novoFilho(Filhoo filho){
		this.filhos.add(filho);
	}
	
}

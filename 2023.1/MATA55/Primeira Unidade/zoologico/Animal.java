package zoologico;

import java.util.ArrayList;

public class Animal{
	private String nome;
	private int idade;
	private Tipo tipo;
	private Comer comer;
	private ArrayList<Animal> animais;
	
	public enum Comer{
		COMEU, NAO_COMEU, TA_COM_FOME
	}
	
	public enum Tipo{
		ELEFANTE, OVELHA, LEAO, TIGRE, PASSARO, TATU, TUBARAO, CROCODILO, COBRA
	}
	
	public Animal(String nome, int idade, Tipo tipo, Comer comer, ArrayList<Animal> animais) {
		this.nome = nome;
		this.idade = idade;
		this.tipo = tipo;
		this.comer = comer;
		this.animais = animais;
	}
	
	public Animal(String nome, int idade, Tipo tipo, Comer comer) {
		this.nome = nome;
		this.idade = idade;
		this.tipo = tipo;
		this.comer = comer;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public ArrayList<Animal> getAnimais() {
		return animais;
	}

	public void setAnimais(ArrayList<Animal> animais) {
		this.animais = animais;
	}

	public Tipo getTipo() {
		return tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	
	public Comer getComer() {
		return comer;
	}
	
	public void setComer(Comer comer) {
		this.comer = comer;
	}
	
	public boolean addAnimal(String nome, int idade, Tipo tipo, Comer comer) {
		if(nome == null) {
			return false;
		}else {
			this.animais.add(new Animal(nome, idade, tipo, comer));
			return true;
		}
	}
	
	public boolean matarAnimal(String nome, int idade, Tipo tipo, Comer comer) {
		if(nome == null) {
			return false;
		}else {
			this.animais.remove(new Animal(nome, idade, tipo, comer));
			return true;
		}
	}
}

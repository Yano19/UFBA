package zoologico;

import java.util.ArrayList;

public class Funcionario{
	private String nome;
	private int idade, horasTrabalhadas = 0, anoExperiencia; 
	private Cargo cargo;
	private ArrayList<Funcionario> funcionarios; 
	private boolean limpouCela;
	
	public enum Cargo{
		ESTAGIARIO, JUNIOR, PLENO, SENIOR
	}
	
	public Funcionario(String nome, Cargo cargo, int idade, int horasTrabalhadas, int anoExperiencia, boolean limpouCela, ArrayList<Funcionario> funcionarios) {
		this.nome = nome;
		this.cargo = cargo;
		this.idade = idade;
		this.horasTrabalhadas = horasTrabalhadas;
		this.anoExperiencia = anoExperiencia;
		this.limpouCela = limpouCela;
		this.funcionarios = funcionarios;
	}
	
	public Funcionario(String nome, Cargo cargo, int idade, int horasTrabalhadas, int anoExperiencia, boolean limpouCela) {
		this.nome = nome;
		this.cargo = cargo;
		this.idade = idade;
		this.horasTrabalhadas = horasTrabalhadas;
		this.anoExperiencia = anoExperiencia;
		this.limpouCela = limpouCela;
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

	public int getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(int horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}

	public int getAnoExperiencia() {
		return anoExperiencia;
	}

	public void setAnoExperiencia(int anoExperiencia) {
		this.anoExperiencia = anoExperiencia;
	}

	public Cargo getCargo() {
		return cargo;
	}

	public void setCargo(Cargo cargo) {
		this.cargo = cargo;
	}
	
	public boolean getLimpouCela() {
		return this.limpouCela;
	}
	
	public ArrayList<Funcionario> getFuncionarios() {
		return funcionarios;
	}

	public void setFuncionarios(ArrayList<Funcionario> funcionarios) {
		this.funcionarios = funcionarios;
	}

	public void setLimpouCela(boolean limpouCela) {
		this.limpouCela = limpouCela;
	}
	
	/*METODO ADICIONAR UM FUNCIONARIO*/
	public boolean addFuncionario(String nome, Cargo cargo, int idade, int horasTrabalhadas, int anoExperiencia, boolean limpouCela){
		if(nome == null) {
			return false;
		}else {
			this.funcionarios.add(new Funcionario(nome, cargo, idade, horasTrabalhadas, anoExperiencia, limpouCela));
			return true;
		}
	}
	
	/*METODO REMOVER UM FUNCIONARIO*/
	public boolean removerFuncionario(Funcionario funcionario) {
		return this.funcionarios.remove(funcionario);
	}
	
	/* Saber se o funcionario é experiente e em qual caego ele se encaixa*/
	public boolean ehExperiente() {
		if(this.anoExperiencia == 0) {
			this.cargo = Cargo.ESTAGIARIO;
		}else if(this.anoExperiencia >= 1 && this.anoExperiencia <3){
			this.cargo = Cargo.JUNIOR;
		}else if(this.anoExperiencia >= 3 && this.anoExperiencia < 5) {
			this.cargo = Cargo.PLENO;
		}else if(this.anoExperiencia >=5) {
			this.cargo = Cargo.SENIOR;
		} else {
			throw new IllegalArgumentException("Ano de experiencia inválido");
		}
		return this.anoExperiencia > 0;
	}
	
	public boolean celaLimpa() {
		if(this.limpouCela) {
			System.out.println("Funcionário já realizou a limpeza da cela.");
			return true;
		}else {
			System.out.println("Funcionário ainda não realizou a limpeza da cela.");
			return false;
		}
	}
	
	public void chegouTrabalho(String nome, int horasTrabalhadas) {
		this.nome = nome;
		this.horasTrabalhadas = 0;
		System.out.println(this.nome + "Chegou no trabalho");
	}
	
	public void saiuTrabalho(String nome, int horasTrabalhadas) {
		this.nome = nome;
		this.horasTrabalhadas = 12;
		System.out.println(this.nome + "Terminou o servico do dia");
	}
}

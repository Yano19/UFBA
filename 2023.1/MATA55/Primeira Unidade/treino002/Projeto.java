import java.util.ArrayList;

public class Projeto{
  private String nome;
  private String clienteNome;
  private int valorHora;
  private ArrayList<Tarefa> tarefas;

  /*-------- CONSTRUTOR ----------*/
  /*PROJETO INICIANDO SEM UMA TAREFA*/
  public Projeto(String nome, String clienteNome, int valorHora){
    this.nome = nome;
    this.clienteNome = clienteNome;
    this.valorHora = valorHora;
    //ArrayList vazio de tarefas
    this.tarefas = new ArrayList<Tarefa>(); 
    //aqui indico que minha lista pode receber qualquer valor
  }
  
  /*-------- CONSTRUTOR ----------*/
  /*PROJETO INICIANDO COM UMA TAREFA*/
  public Projeto(String nome, String clienteNome, int valorHora, String descricaoTarefa) {
   this(nome, clienteNome, valorHora);
    this.tarefas.add(new Tarefa(descricaoTarefa));
  }

    /*-------- CONSTRUTOR ----------*/
    /*PROJETO INICIANDO COM TODAS AS CARACTERISTICAS*/
  public Projeto(String nome, String clienteNome, int valorHora, String descricaoTarefa, String desenvolvedorTarefa){
    this(nome, clienteNome, valorHora);
    this.tarefas.add(new Tarefa(descricaoTarefa, desenvolvedorTarefa));
  }

  /* METODO PARA FINALIZAR A TAREFA */
  public boolean finalizarTarefa(int horas, String descricao){
    for(Tarefa tarefas : tarefas){
      if(tarefas.getDescricao().equals(descricao)){
        tarefas.setStatus("FINALIZADA");
        tarefas.addHorasGastas(horas);
        return true;
      }
    }
    return false;
  }

  /*QUESTÃO DOIS, METODO ADICIONAR TAREFA*/
  public boolean addTarefa(String descricao, String desenvolvedor){
    if(descricao.equals(null) || desenvolvedor.equals(null)){
      return false;
    }else{
      this.tarefas.add(new Tarefa(descricao, desenvolvedor));
      return true;
    }
  }

  /*REALIZAR A SOBRECARGA DO METODO ACIMA*/
  /*sobrecarga seria criar o mesmo metodo mas com parametroas a menos*/
  public boolean addTarefa(String descricao){
    if(descricao.equals(null)){
      return false;
    }else{
      this.tarefas.add(new Tarefa(descricao));
      return true;
    }
  }

  /*QUESTÃO 03: A TAREFA ESTA FINALIZADA*/
  public boolean estaFinalizado(){
    for (Tarefa tarefa: this.tarefas){
      if (!tarefa.getStatus().equals("FINALIZADA")){
        return false;
      }
    }
    return true;
  }

  /*----- MOSTRAR O VALOR DO PROJETO PARA O CLIENTE ------*/
  public String valorProjeto(){
    int horasTotais = 0;
      if(this.estaFinalizado()){
        for(Tarefa tarefa : this.tarefas){
          horasTotais += tarefa.getHorasGastas();
      }
      int valorProjeto = horasTotais * this.valorHora;
      return "Projeto" + this.nome + "Cliente" + this.clienteNome + "Valor R$" + valorProjeto;
    }else {
        return "Projeto não finalizado";
    }
  }

  /*----- METODOS GET E SET ------*/
public String getNome() {
	return nome;
}

public void setNome(String nome) {
	this.nome = nome;
}

public String getClienteNome() {
	return clienteNome;
}

public void setClienteNome(String clienteNome) {
	this.clienteNome = clienteNome;
}

public int getValorHora() {
	return valorHora;
}

public void setValorHora(int valorHora) {
	this.valorHora = valorHora;
}

public ArrayList<Tarefa> getTarefas() {
	return tarefas;
}  
}

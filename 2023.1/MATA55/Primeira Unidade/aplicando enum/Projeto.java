import java.util.ArrayList;

public class Projeto {
/* ADICIONANDO OS ATRIBUTOS */
  private String nome;
  private String clientNome;
/*O PRIVATE ArrayList<Tarefa> tarefas;*/
  private ArrayList<Tarefa> tarefas;
  private int valorHora;

  // Projeto inicializado sem tarefa
  public Projeto(String nome, String clientNome,int valorHora) {
    this.nome = nome;
    this.clientNome = clientNome;
    this.valorHora = valorHora;
    // ArrayList vazio de tarefas
    /*this.tarefas = new ArrayList<Tarefa>()*/
    this.tarefas = new ArrayList<Tarefa>();
  }

  // Projeto inicializado com uma tarefa
  public Projeto(String nome, String clientNome, int valorHora, String descricaoTarefa) {
/*pesquisar no chatgpt a diferença*/
    this(nome, clientNome, valorHora);
    this.tarefas.add(new Tarefa(descricaoTarefa));
  }
  
  public Projeto(String nome, String clientNome, int valorHora, String descricaoTarefa, String desenvolvedorTarefa) {
    this(nome, clientNome, valorHora);
    this.tarefas.add(new Tarefa(descricaoTarefa, desenvolvedorTarefa));
  }
  
  public boolean finalizarTarefa(int horas, String descricao) {
    for(Tarefa tarefa : tarefas) {
      if(tarefa.getDescricao().equals(descricao)) {
        tarefa.setStatus(Tarefa.Status.FINALIZADA);
        tarefa.addHorasGastas(horas);
        return true;
      }
    }
    return false;
  }
  
  //QUESTÃO DOIS, MÉTODO NÚMERO UM: Adicionar Tarefa
  public boolean addTarefa(String descricao, String desenvolvedor){
    if (descricao.equals(null) || desenvolvedor.equals(null)){
      return false;
    }
    else {
      this.tarefas.add(new Tarefa(descricao, desenvolvedor));
      return true;
    }
  }
  //(Ainda QUESTÃO DOIS) Sobrecarga do método acima
  public boolean addTarefa(String descricao){
    if (descricao.equals(null)){
      return false;
    }
    else {
      this.tarefas.add(new Tarefa(descricao));
      return true;
      }
  }

  // Questão 3
  public boolean estaFinalizado(){
    for (Tarefa tarefa: this.tarefas){
      if (!tarefa.getStatus().equals(Tarefa.Status.FINALIZADA)){
        return false;
      }
    }
    return true;
  }

  // QUESTÃO DOIS, MÉTODO NÚMERO QUATRO: Mostrar o valor do projeto ao cliente
  public String valorProjeto() {
    if (this.estaFinalizado()){
      int horasTotais = 0;
      for (Tarefa tarefa : this.tarefas){
        horasTotais += tarefa.getHorasGastas();
      }
      float valorProjeto = horasTotais * this.valorHora;
      return "Projeto" + this.nome + "Cliente" + this.clientNome + "Valor R$" + valorProjeto;
    }
    else {
      return "Projeto não finalizado";
    }
  }
  
  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setClientNome(String clientNome) {
    this.clientNome = clientNome;
  }

  public void setValorHora(int valorHora) {
    this.valorHora = valorHora;
  }

  public float getValorHora() {
    return this.valorHora;
  }

  public String getNome() {
    return this.nome;
  }

  public String getClientNome() {
    return this.clientNome;
  }

  public ArrayList<Tarefa> getTarefa() {
    return this.tarefas;
  }
}

public class Tarefa{
/* APENAS APLICANDO ATRIBUTOS */
  private String descricao;
  private Status status;
  private String desenvolvedor;
  private int horasGastas;

  public enum Status{
    INICIADA, DELEGADA, FINALIZADA
  }
  // Construtor para situação que inicia com desenvolvedor
/*A TAREFA OBRIGATOORIAMENTE DEVE COMEÇAR COMO DELEGADA*/
  public Tarefa(String descricao, String desenvolvedor){
    this.descricao = descricao;
    this.status = Status.DELEGADA;
    this.desenvolvedor = desenvolvedor;
    this.horasGastas = 0;
  }

  // Contrutor para tarefa sem desenvolvedor
/*A TAREFA COMEÇÇA SEM DESENVOLVEDOR, ENTÃO ATRIBUIMOS NULL PARA ELE*/
  public Tarefa(String descricao){
    this.descricao = descricao;
    this.status = Status.INICIADA;
    this.desenvolvedor = null;
    this.horasGastas = 0;
  }
    
  // Designar um desenvolvedor para a tarefa
/* PARA DESIGNAR UM DESENVOLVEDOR NÓS MECHEMOS NO SET*/
  public void setDesenvolvedor(String nome){
    this.desenvolvedor = nome;
  }

  // INCREMENTAR horas gastas
/*HORAS GASTAS VAI RECEBER A QUANTIDADE DE HORAS QUE ELE TRABALHOU*/
  public void addHorasGastas(int horas){
    this.horasGastas += horas;
  }

  // Determinar conclusão de uma tarefa
  public void setStatus(Status status){
    this.status = status;
  }

  // OS VALORES DOS GET ESTÃO NORMAIS
  public String getDescricao(){
    return this.descricao;
  }

  public Status getStatus(){
    return this.status;
  }

  public String getDesenvolvedor(){
    return this.desenvolvedor;
  }

  public float getHorasGastas(){
    return this.horasGastas;
  }

  
}

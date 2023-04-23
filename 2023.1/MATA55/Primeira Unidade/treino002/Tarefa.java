public class Tarefa{
  /*----- ATRIBUTOS -----*/
  private String descricao;
  private String status;
  private String desenvolvedor;
  private int horasGastas;

  /*----- CONSTRUTOR -----*/

  /*não precisamos passar como parametro porque os valores já foram aplicados 
    para as outras
  */
  public Tarefa(String descricao, String desenvolvedor){
    this.descricao = descricao;
    this.status = "DELEGADA";
    this.desenvolvedor = desenvolvedor;
    this.horasGastas = 0;
  }

  /*----- CONSTRUTOR PARA A SITUAÇÃO QUE O PROJETO INCIA SEM O DESENVOLVEDOR -----*/

  /*aqui o desenvolvedor recebe "null", então não precisa ser passado como parametro*/
  public Tarefa(String descricao){
    this.descricao = descricao;
    this.status = "INICIADA";
    this.desenvolvedor = null;
    this.horasGastas = 0;
  }
  
  /*----- METODOS SET -----*/
  public void setDescricao(String descricao){
    this.descricao = descricao;
  }

  /*Determinar a conclusão de uma tarefa*/
  public void setStatus(String status){
    this.status = status;
  }

  /*designando um desenvolvedor para uma tarefa*/
  public void setDesenvolvedor(String nome){
    this.desenvolvedor = nome; 
  }

  /*incrementar as horas gastas*/
  public void addHorasGastas(int horas){
    this.horasGastas += horas;
  }

  /*----- METODOS GET -----*/
  public String getDescricao(){
    return this.descricao;
  }
  
  public String getStatus(){
    return this.status;
  }

  public String getDesenvolvedor(){
    return this.desenvolvedor;
  }

  public float getHorasGastas(){
    return this.horasGastas;
  }
  
}

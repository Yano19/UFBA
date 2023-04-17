/*
    2 - Nesta aplicação é comum realizar atualizações de endereço. 
    Crie um (ou mais) método(s) para atualizar endereço (por exemplo, atualizaEndereco) para a classe Proprietario. 
    O método pode receber como parâmetros os novos valores para rua, número, cep,
    estado e cidade ou pode receber apenas rua,
    número e cep. Caso cidade e estado não sejam informados, o estado e a cidade não devem ser alterados. 
    Esse(s) método(s) não deve(m) retornar nada.
*/


public class Proprietario{
    
   private String nome;
   private String cpf;
   private String identidade;
   private String rua;
   private int numero;
   private String cep;
   private String estado;
   private String cidade;
   
   
   /*------ Construtores --------*/

   public Proprietario(String nome, String cpf, String identidade, String rua, int numero, String cep, String estado, String cidade){
        this.nome = nome;
        this.cpf = cpf;
        this.identidade = identidade;
        this.rua = rua;
        this.numero = numero;
        this.cep = cep;
        this.estado = estado;
        this.cidade = cidade;
   }
   
   /*------ Metodos get --------*/

    public String getNome(){
       return this.nome;
    }
    
    public String getCpf(){
       return this.cpf;
    }
    
    public String getIdentidade(){
       return this.identidade;
    }
    
    public String getRua(){
       return this.rua;
    }
    
    public int getNumero(){
       return this.numero;
    }
    
    public String getCep(){
       return this.cep;
    }
    
    public String getEstado(){
       return this.estado;
    }
    
    public String getCidade(){
       return this.cidade;
    }
   
   /*------ Metodos set --------*/
   
   public void setNome(){
       this.nome = nome;
   }
   
   public void setCpf(){
       this.cpf = cpf;
   }
   
   public void setIdentidade(){
       this.identidade = identidade;
   }
   
   public void setRua(){
       this.rua = rua;
   }
   
   public void setNumero(){
       this.numero = numero;
   }
   
   public void setCep(){
       this.cep = cep;
   }
   
   public void setEstado(){
       this.estado = estado;
   }
   
   public void setCidade(){
       this.cidade = cidade;
   }
   
   public void atualizaEndereco(String rua, int numero, String cep, String estado, String cidade){
        this.rua = rua;
        this.numero = numero;
        this.cep = cep;
        if(estado != null){
            this.estado = estado;
        }
        if(estado != null){
            this.cidade = cidade;
        }
   }
}

/*

   1. Quais a classes vc consegue identificar para este software?
   
   RESPOSTA: A classe Imovel, classe Proprietário e a classe inquilino.

   2. Implemente as classes Imóvel e Proprietário métodos construtores e acessores.    

   Um Imóvel tem um numero de IPTU, rua, número, cep, estado, cidade, tipo (casa, apto) e a utilização (campo, praia)

   Um proprietário tem nome, cpf , identidade, rua, número, cep, estado, cidade.*/

public class Proprietario{
    
   public String nome;
   public String cpf;
   public String identidade;
   public String rua;
   public int numero;
   public String cep;
   public String estado;
   public String cidade;
   
   
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
}











package exercicio_incremental;
/*
Devido a um novo requisito, o sistema deve ser refatorado de forma que não seja possível que Proprietarios tentem 
disponibilizar para locação um Imovel com o mesmo endereço no qual residem. Para isso, refatore as classes Proprietario 
e Imoveis de forma que ao invés de possuírem atributos para rua, número, cidade, estado e cep, possuam Enderecos. Enderecos
irão possuir os atributos: rua, número, cidade, estado e cep. Cada Proprietario terá um Endereco (que representa o endereço
de residência daquele Proprietario) e cada Imovel terá um endereço (que representa o endereço do Imovel)

Estados devem ser representados por suas siglas. Caso uma sigla inválida seja passada, o programa deve indicar um erro.
*/

public class Imovel{
    private int iptu;
    private String tipo;
    private String utilizacao;
    
    /*-------- Construtor -------*/
    
    public Imovel(int iptu, String tipo, String utilizacao){
        this.iptu = iptu;
        this.tipo = tipo;
        this.utilizacao = utilizacao;
    }
    
    /*------ Metodos get -------*/
    
    public int getIptu(){
        return this.iptu;
    }
    
    public String getTipo(){
        return this.tipo;
    }
    
    public String getUtilizacao(){
        return this.utilizacao;
    }
    
    /*-------- Metodos set ---------*/
    
    public void setIptu(int iptu){
        this.iptu = iptu;
    }
    
     public void setTipo(String tipo){
        this.tipo = tipo;
    }
    
    public void setUtilizacao(String utilizacao){
        this.utilizacao = utilizacao;
    }
}

package exercicio_incremental;

/*
Proprietarios podem ter um ou mais Imoveis disponíveis para locação. 
Refatore o sistema para representar essa relação e implemente uma nova funcionalidade que permita que,
dado um tipo de Imovel ("casa", "apto", ...), liste na tela os Imoveis de um Proprietario com o tipo determinado.
Obs: Imoveis podem ser cadastrados independentemente de Proprietarios   
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

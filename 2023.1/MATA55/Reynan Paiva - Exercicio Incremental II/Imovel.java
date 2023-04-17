/*
    1 - No momento da instanciação de um imóvel, quando estado e cidade não forem informados,
    devemos considerar "Bahia" e "Salvador". Implemente uma solução para isso.
*/
   
public class Imovel
{
    private int iptu;
    private String rua;
    private int numero;
    private int cep;
    private String estado;
    private String cidade;
    private String tipo;
    private String utilizacao;
    
    /*-------- Construtor -------*/
    
    //public: pode ser acessado de qualquer classe
    public static final String DEFAULT_ESTADO = "Bahia";
    public static final String DEFAULT_CIDADE = "Salvador";
    
    public Imovel (int iptu, String rua, int numero, int cep, String tipo, String utilizacao){
        this.iptu = iptu;
        this.rua = rua;
        this.numero = numero;
        this.cep = cep;
        this.tipo = tipo;
        this.utilizacao = utilizacao;
        this.estado = DEFAULT_ESTADO;
        this.cidade = DEFAULT_CIDADE;
    }
    
    public Imovel(int iptu, String rua, int numero, int cep, String estado, String cidade, String tipo, String utilizacao){
        this.iptu = iptu;
        this.rua = rua;
        this.numero = numero;
        this.cep = cep;
        this.estado = estado;
        this.cidade = cidade;
        this.tipo = tipo;
        this.utilizacao = utilizacao;
    }
    
    /*------ Metodos get -------*/
    
    public int getIptu(){
        return this.iptu;
    }
    
    public String getRua(){
        return this.rua;
    }
    
    public int getNumero(){
        return this.numero;
    }
    
    public int getCep(){
        return this.cep;
    }
    
    public String getEstado(){
        return this.estado;
    }
    
    public String getCidade(){
        return this.cidade;
    }
    
    public String getTipo(){
        return this.tipo;
    }
    
    public String getUtilizacao(){
        return this.utilizacao;
    }
    
    /*-------- Metodos set ---------*/
    
    public void setIptu(){
        this.iptu = iptu;
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
        this.cidade= cidade;
    }
    
     public void setTipo(){
        this.tipo = tipo;
    }
    
    public void setUtilizacao(){
        this.utilizacao = utilizacao;
    }
}

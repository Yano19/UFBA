package exercicio_incremental;
/*
Devido a um novo requisito, o sistema deve ser refatorado de forma que não seja possível que Proprietarios tentem 
disponibilizar para locação um Imovel com o mesmo endereço no qual residem. Para isso, refatore as classes Proprietario 
e Imoveis de forma que ao invés de possuírem atributos para rua, número, cidade, estado e cep, possuam Enderecos. Enderecos
irão possuir os atributos: rua, número, cidade, estado e cep. Cada Proprietario terá um Endereco (que representa o endereço
de residência daquele Proprietario) e cada Imovel terá um endereço (que representa o endereço do Imovel)

Estados devem ser representados por suas siglas. Caso uma sigla inválida seja passada, o programa deve indicar um erro.
*/
import java.util.Arrays;

public class Endereco{
    
    private String rua;
    private int numero;
    private String cidade;
    private String estado;
    private String cep;

/*-------- Construtor -----------*/
    public Endereco(String rua, int numero, String cidade, String estado, String cep){
        this.rua = rua;
        this.numero = numero;
        this.cidade = cidade;
        this.estado = estado;
        this.cep = cep;
    }
    
    /*------ Metodos get -------*/
    
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
    
    /*------ Metodos set -------*/
    
    public void setRua(String rua){
       this.rua = rua;
   }
   
   public void setNumero(int numero){
       this.numero = numero;
   }
   
   public void setCep(String cep){
       this.cep = cep;
   }
   
   //descobrir se o estado é valido
   public void setEstado(String estado){
        String[] estadosValidos = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
        if(Arrays.asList(estadosValidos).contains(estado)){
            this.estado = estado;
        }
        else{ //indicando que um argumento inválido foi passado para um método ou construtor.
            throw new IllegalArgumentException("A sigla de estado que o usuario deseja adicionar não é valida");
        }
    }
    
   public void setCidade(String cidade){
       this.cidade = cidade;
   }
   
    public void atualizaEndereco(String rua, int numero, String estado, String cidade, String cep){
        setRua(rua);
        setNumero(numero);
        setEstado(estado);
        setCidade(cidade);
        setCep(cep);
   }
    
};


package exercicio_incremental;

/*
Proprietarios podem ter um ou mais Imoveis disponíveis para locação. 
Refatore o sistema para representar essa relação e implemente uma nova funcionalidade que permita que,
dado um tipo de Imovel ("casa", "apto", ...), liste na tela os Imoveis de um Proprietario com o tipo determinado.
Obs: Imoveis podem ser cadastrados independentemente de Proprietarios   
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

package exercicio_incremental;

/*
Devido a um novo requisito, o sistema deve ser refatorado de forma que não seja possível que Proprietarios tentem 
disponibilizar para locação um Imovel com o mesmo endereço no qual residem. Para isso, refatore as classes Proprietario 
e Imoveis de forma que ao invés de possuírem atributos para rua, número, cidade, estado e cep, possuam Enderecos. Enderecos
irão possuir os atributos: rua, número, cidade, estado e cep. Cada Proprietario terá um Endereco (que representa o endereço
de residência daquele Proprietario) e cada Imovel terá um endereço (que representa o endereço do Imovel)

Estados devem ser representados por suas siglas. Caso uma sigla inválida seja passada, o programa deve indicar um erro.
*/
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import exercicio_incremental.Endereco;
import exercicio_incremental.Imovel;

public class Proprietario{
    
   private String nome;
   private String cpf;
   private String identidade;
   private Endereco endereco;
   private List<Imovel> imoveis = new ArrayList<>();
   // adicionando um atributo imovel que será uma lista de objetos da classe imovel

   /*------ Construtores --------*/

   public Proprietario(String nome, String cpf, String identidade, Endereco endereco){
        this.nome = nome;
        this.cpf = cpf;
        this.identidade = identidade;
        this.endereco = endereco;
        this.imoveis = new ArrayList<>():
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
   
   /*------ Metodos set --------*/
   
   public void setNome(String nome){
       this.nome = nome;
   }
   
   public void setCpf(String cpf){
       this.cpf = cpf;
   }
   
   public void setIdentidade(String identidade){
       this.identidade = identidade;
   }
}


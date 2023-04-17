package exercicio_incremental;

/*
Proprietarios podem ter um ou mais Imoveis disponíveis para locação. 
Refatore o sistema para representar essa relação e implemente uma nova funcionalidade que permita que,
dado um tipo de Imovel ("casa", "apto", ...), liste na tela os Imoveis de um Proprietario com o tipo determinado.
Obs: Imoveis podem ser cadastrados independentemente de Proprietarios   
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
        this.imoveis = new ArrayList<>();
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
   
   /*----- Metodo para adicionar imovel --------*/
   
   public void addImovel(Imovel imovel){
       this.imoveis.add(imovel);
   }
   
   /*----- Listas imoveis pelo tipo -------------*/
   public void listarImoveisPeloTipo(String tipo){
       System.out.println("Imóveis do tipo " + tipo + " do proprietário " + this.nome + ":");
       for (Imovel imovel : this.imoveis) { 
           if (imovel.getTipo().equals(tipo)){
               System.out.println("- " + endereco.getRua() + ", " + endereco.getNumero() + ", " + endereco.getCidade() + ", " + endereco.getEstado() + " - " + imovel.getUtilizacao());
           }
       }
   }
       
 }


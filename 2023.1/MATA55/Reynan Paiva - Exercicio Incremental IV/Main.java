package exercicio_incremental;

/*
Proprietarios podem ter um ou mais Imoveis disponíveis para locação. 
Refatore o sistema para representar essa relação e implemente uma nova funcionalidade que permita que,
dado um tipo de Imovel ("casa", "apto", ...), liste na tela os Imoveis de um Proprietario com o tipo determinado.
Obs: Imoveis podem ser cadastrados independentemente de Proprietarios   
*/

import java.util.List;
import java.util.Arrays;
import exercicio_incremental.Endereco;
import exercicio_incremental.Imovel;
import exercicio_incremental.Proprietario;

public class Main{
    public static void main(String[] args){
        //Criando enderecos
        Endereco endereco1 = new Endereco("Rua das Flores", 123, "Salvador", "BA", "41720778");
        Endereco endereco2 = new Endereco("Rua das Palmeiras", 456, "São Paulo", "SP", "04356123");
        Endereco endereco3 = new Endereco("Rua dos Girassóis", 789, "Rio de Janeiro", "RJ", "22041002");
        
        //Criando proprietários
        Proprietario proprietario1 = new Proprietario("José", "000922029","123456789-01", endereco1);
        Proprietario proprietario2 = new Proprietario("Maria", "239230933","987654321-10", endereco2);
        Proprietario proprietario3 = new Proprietario("Pedro", "00909909", "23233232", endereco3);
        //Criando imóveis
        Imovel imovel1 = new Imovel(1, "Casa", "Residencial");
        Imovel imovel2 = new Imovel(2, "Apartamento", "Comercial");
        Imovel imovel3 = new Imovel(3, "Casa", "Residencial");
        Imovel imovel4 = new Imovel(4, "Apartamento", "Residencial");
        
        //Associando imóveis aos proprietários
        proprietario1.addImovel(imovel1);
        proprietario2.addImovel(imovel2);
        proprietario3.addImovel(imovel3);
        
        //Testando a funcionalidade de listar imóveis por tipo de um proprietário
        proprietario1.listarImoveisPeloTipo("Casa");
        proprietario2.listarImoveisPeloTipo("Apartamento");
        proprietario3.listarImoveisPeloTipo("Casa");
        }
    };

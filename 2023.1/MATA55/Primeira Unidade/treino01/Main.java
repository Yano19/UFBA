import java.util.ArrayList;
/* ANOTACOES AULA


*/
class Main {
  public static void main(String[] args) {
    ArrayList<String> arrayDinamico = new ArrayList<String>();

    /*adicionando*/
    arrayDinamico.add("Goku");
    arrayDinamico.add("Vegeta");

    /*removendo*/
    /*pegar o tamanho do meu arrayList*/
    System.out.println("O tamanho do meu array " + arrayDinamico.size());

    /*O NOVO FOR: TIPO nome_variavel : o nome do ArrayList*/
    for(String nome : arrayDinamico){
      System.out.println(nome);
    }

    ArrayList<App> pessoas = new ArrayList<App>();
    App p1 = new App("Reynan", 19);
    App p2 = new App("Angel", 19);
    
    pessoas.add(p1);
    pessoas.add(p2);

    for (App pessoa : pessoas) {
       System.out.println(pessoa.getNome() + " " + pessoa.getIdade());
}
  }
}

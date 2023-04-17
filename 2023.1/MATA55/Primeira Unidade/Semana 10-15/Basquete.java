public class Basquete
{
    private String nome;
    private int idade;
    private String time;
    private int peso;
    private int nascimento;
    
    /*construtores*/
    public static final int DEFAULT_NASCIMENTO = 1990;
    
    public Basquete(String nome, int idade, String time, int peso){
        this.nome = nome;
        this.idade = idade;
        this.time = time;
        this.peso = peso;
        this.nascimento = DEFAULT_NASCIMENTO;
    }
    
    public Basquete(String nome, int idade, String time, int peso, int nascimento){
        this.nome = nome;
        this.idade = idade;
        this.time = time;
        this.peso = peso;
        this.nascimento = nascimento;
    }
    
    /*metodos get*/
    public String getNome(){
        return this.nome;
    }
    
    public int getIdade(){
        return this.idade;
    }
    
    public String getTime(){
        return this.time;
    }
    
    public int getPeso(){
        return this.peso;
    }
    
    public int getNascimento(){
        return this.nascimento;
    }
    
    /*metodos set*/
    
    public void setNome(){
        this.nome = nome;
    }
    
    public void setIdade(){
        this.idade = idade;
    }
    
    public void setTime(){
        this.time = time;
    }
    
    public void setPeso(){
        this.peso = peso;
    }
    
    public void setNascimento(){
        this.nascimento = nascimento;
    }
    
    /*funcao */
    
    public void idadeAtual(){
        int idade = 2023 - this.nascimento;
        System.out.println("a idade atual é de" + " " + idade);
    }
    
    public void cemKilos(){
        int kg = (100 - this.peso);
        if(kg > 100){
            System.out.println("Pesa mais que cem Kilog");
        }else if(kg < 100){
            System.out.println("nao pesa mais que cem kilos");
        }else if(kg == 100){
            System.out.println("Pesa cem kilos");
        }else{
            System.out.println("Favor, verificar se o peso esta sendo passado");
        }
    }
    
    
	public static void main(String[] args) {
	    Basquete j1 = new Basquete("Reynan Paiva", 20, "Phoenix Suns", 67, 2003);
	    j1.idadeAtual();
	    j1.cemKilos();
	}
}


public class Jogador
{
    private String nome;
    private String posicao;
    private String time;
    private int ano_nascimento;
    
    public Jogador(String nome, String posicao, String time, int ano_nascimento){
        this.nome = nome;
        this.posicao = posicao;
        this.time = time;
        this.ano_nascimento = ano_nascimento;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getPosicao(){
        return this.posicao;
    }
    
    public String getTime(){
        return this.time;
    }
    
    public int getAno_nascimento(){
        return this.ano_nascimento;
    }
    
    public void setNome(){
        this.nome = nome;
    }
    
    public void setPosicao(){
        this.posicao = posicao;
    }
    
    public void setTime(){
        this.time = time;
    }
    
    public void setAno_nascimento(){
        this.ano_nascimento = ano_nascimento;
    }
    
    public boolean podeAposentar(Jogador jogador){
        int idade = 2023 - this.ano_nascimento;
        
        if(jogador.posicao.equals("Defesa") && idade >= 40){
            return true;
        } 
        if(jogador.posicao.equals("Ataque") && idade >= 35){
            return true;
        }
        return false;
    }
    
	public static void main(String[] args) {
		Jogador jogador1 = new Jogador("Carlos", "Defesa", "Sao Paulo", 1998);
		/*podeAposentar(jogador1());*/
		System.out.println(jogador1.getNome()+ " " +jogador1.getTime());
	}
}

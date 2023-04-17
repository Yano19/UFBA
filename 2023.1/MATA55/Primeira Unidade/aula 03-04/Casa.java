/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Casa
{
    private int quartos;
    private String cor;
    private float preco;
    
    public Casa(int quartos, String cor, float preco){
        this.quartos = quartos;
        this.cor = cor;
        this.preco = preco;
    }
    
    public int getQuartos(){
        return this.quartos;
    }
    public String getCor(){
        return this.cor;
    }
    public float getPreco(){
        return this.preco;
    }
   
    public void setPreco(float preco){
        this.preco=preco;
    }
    
    public void setCor(String cor){
        this.cor=cor;
    }
    
    public void setQuartos(int quartos){
        this.quartos=quartos;
    }
	public static void main(String[] args) {
		Casa casa1 = new Casa(3, "Vermelho", 12.42f); /*sempre colocar o f no final*/
		Casa casa2 = new Casa(2, "Rosa", 333.22f);
		
		
		
		System.out.println(casa1.getQuartos());
		System.out.println(casa1.getCor());
		System.out.println(casa1.getPreco());
	}
}

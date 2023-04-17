public class Triangulo{
    
    private int x;
    private int y;
    private int z;
    
    public Triangulo(int x, int y, int z){
        /*sempre retorna uma instancia e é publico(maioria das vezes)*/
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public int getX(){
       return this.x;
    }
    
    public int getY(){
        return this.y;
    }
    
    public int getZ(){
        return this.z;
    }
    
    public void setX(){
        this.x = x;
    }
    
    public void setY(){
        this.y = y;
    } 
    
    public void setZ(){
        this.z = z;
    } 
    
    public int soma(int lado1, int lado2, int lado3){
        return (lado1+lado2+lado3);
    }
    
    public void ehEquilatero(int l1, int l2, int l3){
        if((l1 == l2) && (l2 == l3)){
             System.out.println("ehEquilatero");    
        }else{
            System.out.println("nao ehEquilatero");
        }
    }
        
    
    public static void main(String[] args) {
        Triangulo primeiro = new Triangulo(3, 4, 5);
        Triangulo segundo = new Triangulo(4, 6, 7);
        
        System.out.println(primeiro.getX());
        System.out.println(primeiro.getY());
        System.out.println(primeiro.getZ());
        System.out.println(primeiro.soma(primeiro.getX(), primeiro.getY(), primeiro.getZ()));
        primeiro.ehEquilatero(primeiro.getX(), primeiro.getY(),primeiro.getZ());
    }
}

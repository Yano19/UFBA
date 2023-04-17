/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
    static int f1(int h){
        return h+1;
    }
    static int f2(int e){
        return e+2;
    }
    static int f3(int w, int r){
        return (w+r)/2;
    }
	public static void main(String[] args) {
		System.out.println(f3(f1(10), f2(11)));
	}
}

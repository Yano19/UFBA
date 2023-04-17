/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
    /*-------- REQUISITOS DO EXERCICIO -------*/
    
/*
1- Implementar uma classe Banco
2- Atributos:
2.1-Nome do titular
2.2-Numero da conta
2.3-CPF 
2.4-Tipo da conta
	2.4.1-CC, conta corrente
	2.4.2-CP, conta poupança
2.>5-Saldo 
2.6-Status da conta(aberta ou fechada)
3- Métodos:
	3.1-Abrir conta
3.1.1- O sistema deve verificar se já existe uma conta aberta para o titular apresentado.
3.1.2- Ao abrir a conta corrente o titular ganha 50 reias 
		3.1.3- Ao abrir a conta poupança o titular ganha 150 reais
	3.2-Fechar conta
		3.2.1- O sistema deve verificar se o usuário possui conta. 
		3.2.2- O sistema deve verificar se a conta já se encontra fechada.
3.2.3- Se fechar conta os débitos devem ser revisados e o dinheiro deve ser sacado.
	3.3-Depositar
		3.3.1-O sistema deve verificar se o usuário tem conta ativa.
	3.4-Sacar
3.4.1-O sistema deve verificar se a conta do cliente está ativa.
3.4.2-O sistema deve verificar se o saldo na conta é <= a quantidade solicitada para o saque.
	3.5-Pagar mensalidade.
		3.4.1-O sistema deve verificar se a conta do cliente está ativa.
		3.4.2- O cliente paga 20 reais para conta poupança
		3.4.3- O cliente paga 12 reais para conta corrente
*/
    /*poupança em objeto
    ATRIBUTOS
    - numConta - public
    - tipo - protected
    - dono - private
    - saldo - private
    - status - private

    TODOS OS ATRIBUTOS POSSUEM METODOS GET E SET
    METODOS
    - abrirConta() - public
    - fecharConta() - public
    - depositar() - public
    - sacar() - public
    - pagarMensal() - public
    
    
    CONSTRUTOR: metodo é ativado sempre que uma nova classe for instanciada.
    */
    
	public static void main(String[] args) {
		System.out.println();
	}
}

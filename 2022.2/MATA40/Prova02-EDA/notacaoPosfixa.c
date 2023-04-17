#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*      COMO FUNCIONA

        Notação pós-fixa: O OPERADOR É  EXPRESSO APÓS OS SEUS OPERANDOS 
                          NÃO NECESSITA DO USO DOS PARENTESES

        EXEMPLOS PARA VERIFICAR SE O CÓDIGO ESTÁ FUNCIONANDO CORRETAMENTE

        Infixa                      Pós-fixa
        ((4 + 5) * 5)/ 3            4 5 + 5 * 3 /                Resultado = 15
        ((4 * 9) + (8 * 4))         4 9 * 8 4 * +                Resultado = 68

        USO DA PILHA:

        observemos a seguinte expressão:

        4 5 + 5 * 3 /

        Empilhamos ' 4 ', depois empilhamos o ' 5 '. Agora encontramos um operador matemático ' + '.
        A operação será realizada com os dois operadores que estão no topo. Então removo o ' 4 ' e ' 5 ' e realizo a operação '4 + 5'.
        Já temos a expressão (4 + 5) = 9. Então empilho o ' 5 '. Agora encontrei um outro operador matemático ' * '.
        Então desempilho o '9' e '5' e obtemos a operação (9 * 5) = 45.
        Empilhamos o '3'. Agora encontramos novamente outro operador matemático, a ' / '.
        Então desempilho o ' 45 ' e ' 3 ' obtendo a seguinte operação: (45 / 3) = 15.
        Logo, o resultado da nossa operação é 15.

*/

typedef struct  no{
    float valor; //float para nao perder o decimal na divisão
    struct  no *proximo;
} No;

//Funcao que vai empilhar um novo nó na minha pilha
No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;  //recebe um número ao qual estou passando como parâmetro
        novo->proximo = pilha; //recebe a minha pilha
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

/*Funcao que vai desempilhar remover um no, pegar um ponteiro para esse no e retornar esse ponteiro
    se não tiver ninguém na pilha, então o ponteiro será nulo.
*/
No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

/* Operacao matemática   */
float operacoes(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

/* Funcao que vai resolver a minha expressao matematica */
float resolver_exp(char x[]){ /* 4 5 + 5 * 3 / */
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt){
        //acessar o primeito elemento apontado pelo ponteiro e descobrir qual operacao ele é
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacoes(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num); //colocando o resultado de volta para a pilha
            free(n1); //liberar memória do primeiro nó
            free(n2); //liberar memória do segundo nó
        }
        else{
            /*
            Funcao strtol: recebe 3 parametros
            1: string que contem o númer que eu quero converter
            2: adicionamos o NULL, para a funcao desconsiderar outros textos    
            3: base numerica que queremos utilizar
            */
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1); //liberar memória
    return num;
}

int main(){
    char exp[50] = {" 4 5 + 5 * 3 /"};

    printf("Resposta:  %s:\t", exp);
    printf("%f\n", resolver_exp(exp));
}
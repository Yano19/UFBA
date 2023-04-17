#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

//ESTRUTURA RED-BLACK
typedef enum{
  C_VERMELHO,
  C_PRETO
}NO_COR;

//ESTRUTURA DO NÓ
//REGISTRA A ALTURA DO NÓ
typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
    int balanceamento; 
    NO_COR cor;
}No;

//FUNÇÃO CRIA UM NOVO NÓ
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
        novo->cor = C_VERMELHO;
    }
    else
        printf("\nERRO ao alocar nó em novoNo!\n");
    return novo;
}

//FUNÇÃO QUE INDICA QUAL SUBÁRVORE É MAIOR
int maior(int a, int b){
    return (a > b)? a: b;
}

//FUNÇÃO QUE RETORNA A ALTURA DE UM NÓ
int alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;

}
//FUNÇÃO ALTURA DE UMA ÁRVORE
int alturaDaArv(No *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int left = alturaDaArv(raiz->esquerdo);
        int right = alturaDaArv(raiz->direito);
        if(left>right){
            return left + 1;
          }else{
            return right +1;
          }
    }
}

//FUNÇÃO QUNATIDADE DE NÓS NA ARVORE
int QuantoNo(No *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + QuantoNo(raiz->esquerdo) + QuantoNo(raiz->direito);
}

//FUNÇÃO QUE CALCULA E RETORNA O FATOR DE BALANCCEAMENTO DE UM NÓ
//ALTURA DA SUBÁRVORE A ESQUERDA MENOS A AALTURA DA SUBÁRVORE A DIREITA
int fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}


int aux5 = 0;
int fatorDeBalanceamentoo(No *no){
    if(no){
        int left = alturaDaArv(no->esquerdo);
        int right = alturaDaArv(no->direito);
        int fatbal = (left - right);
      //printf("\n\n\tFB ATUAL :%d\n", fatbal); 
      return fatbal;
      }else{
        return 0;
      }
}

int aux7 = 0, n = 1, n1=1, n2=1;
float NB2;
int preOrdem(No *raiz){
  if(raiz == NULL){
    return 0;
  }else{
    //printf("\n\n\t %d° Nó FATOTBALANCEAMENTO: %d", n,fatorDeBalanceamentoo(raiz));
     n++;
    aux7 = aux7 + fatorDeBalanceamentoo(raiz);
    //printf("\n\t %d° Nó SOMA: %d\n", n1, aux7);
    int qtdNO = QuantoNo(raiz);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
    //printf("\n\t\tQANTIDADE DE NO: %d\n", qtdNO);
   // printf("\n\t %d° Nó SOMA FINAL: %d\n", n1, aux7);
    //printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n2, NB);
    float NB = ((float)aux7/qtdNO);
    //printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n2, NB);
    n1++;
   // NB2 = fmax(NB, - NB);
    NB2 = NB * -1;
    printf("\n\n\t %d° NIVEL DE BALANCEAMENTO: %.2f", n2, NB2);
    n2++;
  }  
}


//FUNÇÃO CASO 1 ROTAÇÃO A DIREITA
//QUANDO A ÁRVORE ESTÁ DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É POSITIVO (DESBALANCEADA A ESQUERDA)
No* rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerdo; // y aponta para a subárvore esquerda da raiz r
    f = y->direito;  // f aponta para o filho direito de y

    y->direito = r;   // o filho direito de y passa a ser a raiz r
    r->esquerdo = f;  // o filho esquerdo de r passa a ser f

    y->cor = r->cor;
    r->cor = C_VERMELHO;    
  
    // recalcula a altura dos nós que foram movimentados
    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
 
    }

//FUNÇÃO CASO 2 ROTAÇÃO A ESQUERDA
//QUANDO A ÁRVORE ESTÁ DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É NEGATIVO (DESBALANCEADA A DIREITA)
No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direito; // y aponta para a subárvore direita da raiz r
    f = y->esquerdo; // f aponta para o filho esquerdo de y

    y->esquerdo = r; // o filho esquerdo de y passa a ser a raiz r
    r->direito = f; // o filho direito de r passa a ser f

    y->cor = r->cor;
    r->cor = C_VERMELHO;
    // recalcula a altura dos nós que foram movimentados
    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
   }

//FUNÇÃO CASO 3 DUPLA ROTAÇÃO - ROTAÇÃO ESQUERDA DIREITA
//QUANDO A ÁRVORE ESTA DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É POSITIVO (DESBALANCEADA A ESQUERDA)
//PORÉM SUA SUBÁVORE ESTÁ DESALINHADA PARA DIREITA
No* rotacaoEsquerdaDireita(No *r){
    r->esquerdo = rotacaoEsquerda(r->esquerdo); //aplica a função rotação a esquerda na subárvore esquerda de r
    return rotacaoDireita(r);                  //aplica a função rotação a direita na árvore resultante

}

//FUNÇÃO CASO 4 DUPLA ROTAÇÃO - ROTAÇÃO DIREITA ESQUERDA
//QUANDO A ÁRVORE ESTA DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É NEGATIVO (DESBALANCEADA A DIREITA)
//PORÉM SUA SUBÁVORE ESTÁ DESALINHADA PARA ESQUERDA
No* rotacaoDireitaEsquerda(No *r){
    r->direito = rotacaoDireita(r->direito); //aplica a função rotação a direita na subárvore direita de r
    return rotacaoEsquerda(r);              //aplica a função rotação a esquerda na árvore resultante
    
}

int num;
int contador(){
    num = num + 1;
}


//FUNÇÃO BALANCEAR
int aux = 0, num = 0, QQQ = 0, rodada = 1;
No* balancear(No *raiz){
  int fb = fatorDeBalanceamento(raiz);
  QQQ = QuantoNo(raiz);
  //printf("\n\tQuantidade De NÓ: %d", QQQ);
    if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)   {  //Rotação à direita
        raiz = rotacaoDireita(raiz);
        contador();
        //printf("\nrotacao realizada Direita");
        aux++;
        //printf("\nQuantidade de rotacoes: %d", aux);
       //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR); 
 }   else if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0){ //Rotação à esquerda
        raiz = rotacaoEsquerda(raiz);
        contador();
          //printf("\n\trotacao realizada Esquerda");
          aux++;
       // printf("\n\tQuantidade de rotacoes: %d", aux);
        // printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0){ //Rotação esquerda direita
        raiz = rotacaoEsquerdaDireita(raiz);
         contador();
          // printf("\n\trotacao realizada EsquerdaDireita");
           aux = aux + 2;
        //printf("\n\tQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0){ //Rotação direita esquerda
        raiz = rotacaoDireitaEsquerda(raiz);
        contador();
        //printf("\n\trotacao realizada DireitaEsquerda");
          aux = aux + 2;
        //printf("\nQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
  }
     float mediaRotacao = (aux/(float)QQQ);
      printf("\n\t\n \t-> MÉDIA DE ROTAÇÕES: %.2f\n", mediaRotacao);
    return raiz;
}

//FUNCAO PARA VERIFICAR SE O NÓ É VERMELHO
int eh_vermelho(No *raiz){
  if(raiz == NULL)
    return 0;
  return raiz->cor == C_VERMELHO ? 1 : 0;
}

//FUNCAO PARA INVERTER CORES
void inverterCor(No *raiz){
  raiz->cor = C_VERMELHO;
  raiz->esquerdo->cor = C_PRETO;
  raiz->direito->cor = C_PRETO;
  
}


//FUNÇÃO INSERÇÃO DE UM NOVO NÓ NA ÁRVORE
int aux3 = 0, aux4 = 0, aux6 = 0;
No* inserir(No *raiz, int x){
    if(raiz == NULL) //árvore vazia
        return novoNo(x);
    else{ //inserção será à esquerda ou à direita
        if(x < raiz->valor){
            raiz->esquerdo = inserir(raiz->esquerdo, x);
          }else if(x > raiz->valor){
            raiz->direito = inserir(raiz->direito, x);
          }    
          else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }
    
    //Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    //verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
   /* raiz->balanceamento = fatorDeBalanceamentoo(raiz);
    aux3 = fatorDeBalanceamento(raiz);
    aux4 = aux4 + aux3;
    printf("\n\tSoma Dos Fatores: %d\n", aux4);*/
    return raiz;
}

No* inserirRB(No *raiz, int x){
    //raiz->cor = C_PRETO;
    if(raiz == NULL) //árvore vazia
        return novoNo(x);
    else{ //inserção será à esquerda ou à direita
        if(x < raiz->valor){
            raiz->esquerdo = inserir(raiz->esquerdo, x);
          }else if(x > raiz->valor){
            raiz->direito = inserir(raiz->direito, x);
          }

          //VERMELHO E PRETA ROTAÇÕES
          if(eh_vermelho(raiz->direito) && !eh_vermelho(raiz->esquerdo)){
            rotacaoEsquerda(raiz);
          }
          if(eh_vermelho(raiz->esquerdo) && eh_vermelho(raiz->direito)){
            rotacaoDireita(raiz);
          }
          if(eh_vermelho(raiz->direito) && eh_vermelho(raiz->esquerdo)){
            inverterCor(raiz);
          }        
          else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }
    
    //Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    //verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
   /* raiz->balanceamento = fatorDeBalanceamentoo(raiz);
    aux3 = fatorDeBalanceamento(raiz);
    aux4 = aux4 + aux3;
    printf("\n\tSoma Dos Fatores: %d\n", aux4);*/
    return raiz;
}

//FUNÇÃO IMPRIMIR
void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

//FUNÇÃO BUSCAR
No* buscar(No *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar(raiz->esquerdo, num);
        else
            return buscar(raiz->direito, num);
    }
    return NULL;
}

//FUNÇÃO NÍVEL DE BALANCEAMENTO


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

No* prog_exp(No* raiz){
    imprimir(raiz, 1);
    preOrdem(raiz);
    if((balancear(raiz)) != NULL){
      printf("\n\n\tMEDIA DE ROTAÇÕES FINAL: ");
      balancear(raiz);
    }
}

int dado, dadoRB;
No* prog_print(char f[], No *raiz, No *raizRB)
{
  int fatb = 0;
    FILE *file = fopen(f, "r");
  if(file){
    while(fscanf(file, "%d", &dado) != -1){
    //printf("%d\n", dado);
    raizRB = inserirRB(raizRB, dado);
    raiz = inserir(raiz, dado);
    //imprimir(raiz, 1);
    /*printf("\n\n\tQUANTIDADE DE NÓ DA ÁRVORE: %d", QuantoNo(raiz));
    printf("\n\tALTURA DA ARVORE: %d\n", alturaDaArv(raiz)); */
      
      //FATOR DE BALANCEAMENTO DA RAIZ: EXIBIR
  /*  int left = alturaDaArv(raiz->esquerdo);
    int right = alturaDaArv(raiz->direito);
    if(left>right){
      fatb = left - right;
      printf("\tFATOR DE BALANCEAMENTO DA RAIZ: %d\n", fatb);
    }else{
      fatb = left - right;
      printf("\tFATOR DE BALANCEAMENTO DA RAIZ: %d\n", fatb);
    }     */
  }
   prog_exp(raiz);
    }else{
        printf("\nArquivo não pode ser aberto!\n");
        getchar();
        exit(0);
    }
  return raiz;
  }


int main(){
    int opcao, valor;
    No *raiz = NULL;
    No *raizRB = NULL;
    No *busca = NULL;
    char minhaEntrada[] = ("input1.txt");
    prog_print(minhaEntrada, raiz, raizRB);
    
   
  
    /*do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir e FB Nós\n\t4 - Buscar\n\t5 - Altura da Arvore e FB da Raiz\n\t6 - Quantidade de Nos\n\t7 - Contador de Rotacoes\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Saindo");
                break;
            case 1:
                printf("\tDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("\tDigite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
            case 3:
                imprimir(raiz, 1);
                preOrdem(raiz);
                break;
            case 4:
                printf("\n\tDigite o valor a ser procurado: ");
                scanf("%d", &valor);
                busca = buscar(raiz, valor);
                if(busca)
                    printf("\n\tValor Encontrado: %d\n", busca->valor);
                else
                    printf("\n\tValor Nao Encontrado!\n");
                break;
            case 5:
                printf("\n\tAltura da Arvore: %d\n", alturaDaArv(raiz));   
                int left = alturaDaArv(raiz->esquerdo);
                int right = alturaDaArv(raiz->direito);
                if(left>right){
                  fatb = left - right;
                  printf("\tFator de Balanceamento da raiz: %d\n", fatb);
                }else{
                  fatb = left - right;
                  printf("\tFator de Balanceamento da raiz: %d\n", fatb);
                }
                break;
            case 6:
                printf("\n\tQuantidade de Nos da Arvore: %d\n\n", QuantoNo(raiz));
                break;
            case 7:
                printf("\n\tQuantidade de Rotacoes Realizadas: %d\n\n", contador());
                break;
            default:
                printf("\n\tOpcao Invalida\n");
            }
    }while(opcao != 0);
*/
    return 0;
}
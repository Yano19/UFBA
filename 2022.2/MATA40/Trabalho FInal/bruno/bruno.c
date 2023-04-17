#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO NÓ
//REGISTRA A ALTURA DO NÓ
typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}No;

//FUNÇÃO CRIA UM NOVO NÓ
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
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
        if(left>right)
            return left + 1;
        else
            return right +1;
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

//FUNÇÃO CONTADOR DE ROTAÇÕES
int num = 0;
int contador(){
num = num + 1;
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

//FUNÇÃO BALANCEAR
No* balancear(No *raiz){
    int fb = fatorDeBalanceamento(raiz);

    if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0){     //Rotação à direita
        raiz = rotacaoDireita(raiz);
        contador();
    }else if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0){ //Rotação à esquerda
        raiz = rotacaoEsquerda(raiz);
         contador();
     } else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0){ //Rotação esquerda direita
        raiz = rotacaoEsquerdaDireita(raiz);
         contador();
     }else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0){ //Rotação direita esquerda
        raiz = rotacaoDireitaEsquerda(raiz);
         contador();
     }
    return raiz;
}

//FUNÇÃO INSERÇÃO DE UM NOVO NÓ NA ÁRVORE
No* inserir(No *raiz, int x){
    if(raiz == NULL) //árvore vazia
        return novoNo(x);
    else{ //inserção será à esquerda ou à direita
        if(x < raiz->valor)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if(x > raiz->valor)
            raiz->direito = inserir(raiz->direito, x);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }

    //Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    //verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

//FUNÇÃO REMORÇÃO DE UM NÓ EM UMA ÁRVORE
No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                //printf("Elemento folha removido: %d!\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    No *aux = raiz->esquerdo;
                    while(aux->direito != NULL)
                        aux = aux->direito;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    //printf("Elemento trocado: %d!\n", chave);
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    //printf("Elemento com 1 filho removido: %d!\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
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

int main(){
    int opcao, valor;
    No *raiz = NULL;
    No *busca = NULL;

    do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - Buscar\n\t5 - Altura da Arvore\n\t6 - Quantidade de Nos\n\t7 - Contador de Rotacoes\n\n");
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
                printf("\n\tAltura da Arvore: %d\n\n", alturaDaArv(raiz));
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

    return 0;
}
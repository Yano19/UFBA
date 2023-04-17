/*
MESMA QUANTIDADE DE NÍVEIS PARA AMBAS AS SUBARVORES
TANTO PARA DIREITA QUANTO PARA ESQUERDA

MAIOR QUE 1 E MENOR QUE -1 = DESEQUILIBRADA

corrigir com rotações:

rotação a esquerda
rotação a direita
rotação dupla a esquerda
rotação dupla a direita

TODO NÓ PRECISA TER UM CAMPO "ALTURA"

typedef struct node{
  int valor;
  struct node *left;
  struct node *right;
  short altura; //short ocupa apenas 2 bytes de memória
}Node;

CRIAR UM NOVO NÓ

Node* newNode(int x){
  Node *new = malloc(sizeof(Node));
  if(new){
  new->valor = x;
  new->left = NULL;
  new->right = NULL;
  new->altura = 0;
} else{
  printf("\nERRO ao alocar um novo NO!\n");
  return novo;
}

DESCOBRIR A ALTURA DE CADA NÓ
PARA FAZER ISSO, PRECISAMOS DESCOBRIR A ALTURA DA SUBARVORE DA ESQUERDA E DA DIREITA
DADA A ALTURA DE DUAS SUBARVORES, RETORNO O MAIOR VALOR

short maior(short a, short b){
  return (a > b)? a: b;
}

ALTURA DE UM NÓ:
retorna a altura de um NÓ ou -1 caso ele seja null.

short alturaDoNode(Node *node){
  if(node == NULL){
    return -1;
  }else{
    return(node->altura);
  }
}

FATOR DE BALANCEAMENTO:
pode ser, no máximo 1 ou -1.
fator de balanceamento negativo: DIREITA
fator de balanceamento positivo: ESQUERDA

short fatorDeBalanceamento(Node *node){
  if(node){
    return (alturaDoNode(node->left)) - (alturaDoNode(node->direita));
  }else{
    return 0;
  }
}

ROTAÇÃO À ESQUERDA:

10                 25
  25             10  32
    32
    
r = 10;
y = 25;

FUNCAO PARA ROTAÇÃO A ESQUERDA

Node *rotacaoEsquerda(Node *r){
  Node *y, *f;
  y = r->right;
  f = y->left;
  y->left = r;
  r->right = f;
  
  r->altura = maior(alturaDoNode(r->left), alturaDoNode(r->right)) + 1;
  y->altura = maior(alturaDoNode(y->left), alturaDoNode(y->right)) + 1;
  
  return y;
}

FUNCAO PARA ROTAÇÃO A DIREITA
precisamos fazer a rotação por causa do fator de balanceamento

    50          35
   35         20  50
  20
  
35 SERÁ A RAIZ DA ARVORE E O 50 O FILHO DO 35

r = 50 e y = 35

Node *rotacaoDireita(Node *r){
  Node *y, *f;
  y = r->left;
  f = y->right;
  y->right = r;
  r->left = f;
  r->altura = maior(alturaDoNode(r->left), alturaDoNode(r->right)) + 1;
  y->altura = maior(alturaDoNode(y->left), alturaDoNode(y->right)) + 1;
  
  return y;
  
}

ROTACOES DUPLAS:

ROTACAO DIREITRA ESQUERDA: juncao de uma rotacao a direita e a esquerda

100           100              150
  200           150          100  200
150               200


Node* rotacaoDireitaEsquerda(Node *r){
  r->right = rotacaoRight(r->right);
  return rotacaoLeft(r);
}


ROTACOES DUPLAS:

ROTACAO ESQUERDA DIREITA: juncao de uma rotacao a esquerda e a direita

  200       200      150
100       150     100   200
  150    100

Node* rotacaoEsquerdaDireita(Node *r){
  r->left = rotacaoLeft(r->left);
  return rotacaoRight(r);
}


INSERÇÃO
altera a altura da arvore || Nao aceitar repetição de elementos

Node* inserir(Node *raiz, int x){
  if(raiz == NULL){
    return newNode(x);
  }else{
    if(x < raiz->valor){
      raiz->left = inserir(raiz->left, x);
    }else if(x > raiz->valor){
      raiz->right = inserir(raiz->right, x);
    }else{
      printf("\nInsercao nao realizada\n");
    }
  }
  raiz->altura = maior(alturaDoNode(raiz->left), alturaDoNode(raiz->right)) +1);
  raiz = balancear(raiz);
  return raiz;
}

BALANCEAR
determinar qual rotação iremos realizar
caso a raiz esteja desbalanceada, ela seŕa balanceada.

Node* balancear(No *raiz){
  short fb = fatorDeBalanceamento(raiz);
  
  //rotacao a esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->right) <= 0){
      raiz = rotacaoEsquerda(raiz);
    }
  //rotacao a direito
    else if(fb > 1 && fatorDeBalanceamento(raiz->left) >= 0){
      raiz = rotacaoDireita(raiz);
    }
  //rotacao dupla esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->left) < 0{
      raiz = rotacaoEsquerdaDireira(raiz);
    }
  //rotacao dupla direita
  else if(fb < -1 && fatorDeBalanceamento(raiz->right) > 0{
      raiz = rotacaoDireiraEsquerda(raiz);
  }
  
  return raiz;
}


Node *remocao(Node *raiz, int chave){
  if(raiz == NULL){
    pŕintf("\nValor nao encontrado!\n");
    return NULL;
  } else{ //procurar um nó para remover
    if(raiz->valor == chave){
      //remover os nós que nao tem filho
      if(raiz->left == NULL && raiz->right == NULL){
        free(raiz);
        printf("Elemento folha removido: %d!\n", chave);
        return NULL;
      }else{
        //remover nós que possem 2 filhos
        if(raiz->left != NULL && raiz->right != NULL){
          Node *aux = raiz->left;
          while(aux->right != NULL){
            aux = aux->right;
          }
          raiz->valor = aux->valor;
          aux->valor = chave;
          printf("\nElemento trocado: %d !\n", chave);
          return raiz;
        }else{
          //remover nós que possuem apenas 1 filho
          No* aux;
            if(raiz->left != NULL){
              aux = raiz->left;
            } else{
              aux = raiz->right;
            }
            free(raiz);
            printf("\nElemento com 1 filho removido: %d\n", chave);
            return aux;
        }
      }
    } else{
        if(chave < raiz->valor){
          raiz->left = remover(raiz->left, chave);
        }else{
           raiz->right = remover(raiz->right, chave);
      } 
  }
  
  raiz->altura = maior(alturaDoNode(raiz->left), alturaDoNode(raiz->right)) + 1;
  raiz = balancear(raiz);
  return raiz;
  
  IMPRIMIR UMA ARVRE AVL
  
  void imprimir(Node *raiz, int nivel){
    int i;
    if(raiz){
      imprimir(raiz->right, nivel + 1);
      printf("\n\n");
      for(i = 0; i < nivel; i++){
        printf("\t");
      }
      printf("%d", raiz->valor);
      imprimir(raiz->left, nivel + 1);
    }
  }
}

FUNCAO MAIN

int main(){
  No *raiz = NULL;
  
  do{
    printf("\n\n\t0 - Sair\n\t1- Inserir\n\t2- Remover\n\t3 - Imprimir\n\n");
    scanf("%d", &opcao);
    switch(opaco){
      case 0:
        printf("Saindo!!!");
        break;
       case 1:
        printf("\tDigite o valor a ser inserido: ");
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
        break;
       case 2:
        printf("\tDigite o valor a ser Removido: ");
        scanf("%d", &valor);
        raiz = remover(raiz, valor);
        break;
       case 3:
        imprimir(raiz, 1);
        break;
       default:
       print("\nOpcao Invalida!!!\n");
    }
   }while(opcao != 0);
  return 0;
 } 
}
}
*/

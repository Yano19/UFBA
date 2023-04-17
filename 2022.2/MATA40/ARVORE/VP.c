#include <stdio.h>
#include <stdlib.h>

typedef struct ARN{
  struct ARN *left;
  struct ARN *right;
  int value;
} ARN;


ARN *ARN_Criar(int value){
  ARN* novo = malloc(sizeof(ARN));
  if(novo != NULL){
    novo->left = NULL;
    novo->right = NULL;
    novo->value = value;
  }  
  return novo;
}

void printtabs(int numtabs){
  for(int i = 0; i < numtabs; i++){
    printf("\t");
  }
}

void treePrint_rec(ARN *root, int level){
  if(root == NULL){
    printtabs(level);
    printf("--<empty>--\n");
    return;
  }
   printtabs(level);
  printf("value = %d\n", root->value);
   printtabs(level);
  printf("left\n");
  treePrint_rec(root->left, level + 1);
   printtabs(level);
  printf("right\n");
  treePrint_rec(root->right, level + 1);
   printtabs(level);
  printf("done\n");
}

void treePrint(ARN *root){
  treePrint_rec(root, 0);
}

int main(){
  ARN *n1 = ARN_Criar(10);
  ARN *n2 = ARN_Criar(11);
  ARN *n3 = ARN_Criar(12);
  ARN *n4 = ARN_Criar(13);
  ARN *n5 = ARN_Criar(9);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;

  treePrint(n1);
  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);

}


/*
ARVORE SEMIBALANCEADA
TEM 2 ATRIBUTOS: PAI E COR
coloração é utilizada para realizar o balannceamento da arvore
todo nó inserido tem cor VERMELHA


*/


/*
static inline int eh_vermelho(ARN *A){
  if(A == NULL){
    return 0;
   } return A->cor == C_VERMELHO ? 1 : 0;
}   


static void inverter_cores(ARN *A){
  A->cor = C_VERMELHO;
  A->left->cor = C_PRETO;
  A->right->cor = C_PRETO;
}


static void rot_left(ARN **A){
  ARN *h, *x;
  h = *A;
  x = h->right;
  h->right = x->left;
  x->left = h;
  x ->cor = h->cor;
  h->cor = C_VERMELHO;
  *A = x;
}


static void rot_right(ARN **A){
  ARN *h, *x;
  h = *A;
  x = h->left;
  h->left = x->right;
  x->right = h;
  x ->cor = h->cor;
  h->cor = C_VERMELHO;
  *A = x;
}


void ARN_inserir_R(ARN **A, int chave, int valor){
  if(*A == NULL){
    *A = ARN_Criar(chave, valor);
    return;
  }
  if(chave < (*A)->chave){
    ARN_Inserir_R(&(*A)->left, chave, valor);
  }
  if(chave > (*A)->chave){
   ARN_Inserir_R(&(*A)->right, chave, valor);
  }
  
  if(eh_vermelho((*A)->right && !eh_vermelho((*A)->left))){
    rot_left(A);
  }
  
  if(eh_vermelho((*A)->left && eh_vermelho((*A)->left->left))){
    rot_right(A);
  }
  
  if(eh_vermelho((*A)->left && eh_vermelho((*A)->right))){
    inverter_cores(*A);
  }
  
}

void ARN_inserir(ARN **A, int chave, int valor){
  ARN_inserir_R(A, chave, valor);
  (*A)->cor = C_PRETO;
}


int main(int argc, char** argv){
  ARN *A = NULL;
  ARN_Inserir(&A, (int)'U', 0);
  ARN_ImprimirC(A, 0, 'r');
  ARN_Inserir(&A, (int)'T', 0);
  ARN_ImprimirC(A, 0, 'r');
  ARN_Inserir(&A, (int)'F', 0);
  ARN_ImprimirC(A, 0, 'r');
  ARN_Inserir(&A, (int)'P', 0);
  ARN_ImprimirC(A, 0, 'r');
  ARN_Inserir(&A, (int)'R', 0);
  ARN_ImprimirC(A, 0, 'r');
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum{
  C_VERMELHO,
  C_PRETO
}ARN_COR;

typedef struct ARN{
  struct ARN *left;
  struct ARN *right;
  int valor;
  int chave;
  ARN_COR cor;
}ARN;

static ARN *ARN_Criar(int chave, int valor){
  ARN* novo;
  novo = malloc(sizeof(ARN));
  novo->chave = chave;
  novo->valor = valor;
  novo->cor = C_VERMELHO;
  novo->left = NULL;
  novo->right = NULL;
  
  return novo;
}

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
    ARN_inserir_R(&(*A)->left, chave, valor);
  }
  if(chave > (*A)->chave){      
   ARN_inserir_R(&(*A)->right, chave, valor);
  }
  
  if(eh_vermelho((*A)->right) && !eh_vermelho((*A)->left)){
    rot_left(A);
  }
  
  if(eh_vermelho((*A)->left) && eh_vermelho((*A)->left->left)){
    rot_right(A);
  }
  
  if(eh_vermelho((*A)->left) && eh_vermelho((*A)->right)){
    inverter_cores(*A);
  }
}

void ARN_inserir(ARN **A, int chave, int valor){
  ARN_inserir_R(A, chave, valor);
  (*A)->cor = C_PRETO;
}

void inorderTraversal(ARN *node, int level) {
  if (node) {
    inorderTraversal(node->right, level +1);
    printf("\n\n");
    for(int i = 0; i < level; i++){
      printf("\t");
    }
    printf("%d  ", node->valor);
    inorderTraversal(node->left, level + 1);
  }
  return;
}

ARN *root = NULL;

int main() {
  int option, data;
  ARN *A = NULL;
  while (1) {
    printf("1. Insertion\t2. Deletion\n");
    printf("3. Traverse\t0. Exit");
    printf("\nEnter your choice:");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("Enter the element to insert:");
        scanf("%d", &data);
        ARN_inserir(&A, data, 0);
        break;
      case 2:
        printf("Enter the element to delete:");
        scanf("%d", &data);
        break;
      case 3:
        inorderTraversal(root, 1);
        printf("\n");
        break;
      case 0:
        break;
      default:
        printf("Not available\n");
        break;
    }
    printf("\n");
  }
  return 0;
}
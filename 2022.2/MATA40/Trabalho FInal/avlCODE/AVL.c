#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
  short height;
} Node;

Node *newNode(int x)
{
  Node *new = malloc(sizeof(Node));
  if (new)
  {
    new->value = x;
    new->left = NULL;
    new->right = NULL;
    new->height = 0;
  }
  else
  {
    printf("\nERRO ao alocar um novo NO!\n");
    return new;
  }
}

short max(short a, short b)
{
  return (a > b) ? a : b;
}

short nodeHeight(Node *node)
{
  if (node == NULL)
  {
    return -1;
  }
  else
  {
    return (node->height);
  }
}

short fatorDeBalanceamento(Node *node)
{
  if (node)
  {
    return (nodeHeight(node->left)) - (nodeHeight(node->right));
  }
  else
  {
    return 0;
  }
}

int altura(Node *root)
{
  if (root == NULL)
  {
    return -1;
  }
  else
  {
    int esq = altura(root->left);
    int dir = altura(root->right);
    if (esq > dir)
    {
      return esq + 1;
    }
    else
    {
      return dir + 1;
    }
  }
}

Node *leftRotate(Node *r)
{
  Node *y, *f;
  y = r->right;
  f = y->left;
  y->left = r;
  r->right = f;

  r->height = max(nodeHeight(r->left), nodeHeight(r->right)) + 1;
  y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

  return y;
}

Node *rightRotate(Node *r)
{
  Node *y, *f;
  y = r->left;
  f = y->right;
  y->right = r;
  r->left = f;
  r->height = max(nodeHeight(r->left), nodeHeight(r->right)) + 1;
  y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

  return y;
}

Node *rotacaoDireitaEsquerda(Node *r)
{
  r->right = rightRotate(r->right);
  return leftRotate(r);
}

Node *rotacaoEsquerdaDireita(Node *r)
{
  r->left = leftRotate(r->left);
  return rightRotate(r);
}

Node *balancear(Node *root)
{
  short fb = fatorDeBalanceamento(root);

  // rotacao a esquerda
  if (fb < -1 && fatorDeBalanceamento(root->right) <= 0)
  {
    root = leftRotate(root);
  }
  // rotacao a direito
  else if (fb > 1 && fatorDeBalanceamento(root->left) >= 0)
  {
    root = rightRotate(root);
  }
  // rotacao dupla esquerda
  else if (fb > 1 && fatorDeBalanceamento(root->left) < 0)
  {
    root = rotacaoEsquerdaDireita(root);
  }
  // rotacao dupla direita
  else if (fb < -1 && fatorDeBalanceamento(root->right) > 0)
  {
    root = rotacaoDireitaEsquerda(root);
  }

  return root;
}

Node *insert(Node *root, int x)
{
  if (root == NULL)
  {
    return newNode(x);
  }
  else
  {
    if (x < root->value)
    {
      root->left = insert(root->left, x);
    }
    else if (x > root->value)
    {
      root->right = insert(root->right, x);
    }
    else
    {
      printf("\nInsercao nao realizada\n");
    }
  }
  root->height = max(nodeHeight(root->left), nodeHeight(root->right) + 1);
  root = balancear(root);
  return root;
}

Node *remocao(Node *root, int chave)
{
  if (root == NULL)
  {
    printf("\nValor nao encontrado!\n");
    return NULL;
  }
  else
  { // procurar um nó para remover
    if (root->value == chave)
    {
      // remover os nós que nao tem filho
      if (root->left == NULL && root->right == NULL)
      {
        free(root);
        printf("Elemento folha removido: %d!\n", chave);
        return NULL;
      }
      else
      {
        // remover nós que possem 2 filhos
        if (root->left != NULL && root->right != NULL)
        {
          Node *aux = root->left;
          while (aux->right != NULL)
          {
            aux = aux->right;
          }
          root->value = aux->height;
          aux->value = chave;
          printf("\nElemento trocado: %d !\n", chave);
          return root;
        }
        else
        {
          // remover nós que possuem apenas 1 filho
          Node *aux;
          if (root->left != NULL)
          {
            aux = root->left;
          }
          else
          {
            aux = root->right;
          }
          free(root);
          printf("\nElemento com 1 filho removido: %d\n", chave);
          return aux;
        }
      }
    }
    else
    {
      if (chave < root->value)
      {
        root->left = remocao(root->left, chave);
      }
      else
      {
        root->right = remocao(root->right, chave);
      }
    }

    root->height = max(nodeHeight(root->left), nodeHeight(root->right)) + 1;
    root = balancear(root);
    return root;
  }
}

void imprimir(Node *root, int nivel)
{
  int i;
  if (root)
  {
    imprimir(root->right, nivel + 1);
    printf("\n\n");
    for (i = 0; i < nivel; i++)
    {
      printf("\t");
    }
    printf("%d", root->value);
    imprimir(root->left, nivel + 1);
  }
}

int main()
{
  int opcao, value;
  Node *root = NULL;

  do
  {
    printf("\n\n\t0 - Sair\n\t1- Inserir\n\t2- Remover\n\t3 - Imprimir\n\t4 - Altura\n\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 0:
      printf("Saindo!!!");
      break;
    case 1:
      printf("\tDigite o valor a ser inserido: ");
      scanf("%d", &value);
      root = insert(root, value);
      break;
    case 2:
      printf("\tDigite o valor a ser Removido: ");
      scanf("%d", &value);
      root = remocao(root, value);
      break;
    case 3:
      imprimir(root, 1);
      break;
    case 4:
      printf("\naltura: %d\n", altura(root));
      break;
    default:
      printf("\nOpcao Invalida!!!\n");
    }
  } while (opcao != 0);
  return 0;
}

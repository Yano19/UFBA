#include<stdio.h> // for printf
#include<stdlib.h> // for malloc
#include<stdio.h> // for printf

typedef struct data {
  int matricula; // id do item de dado
  int nitens;    // no. de itens a serem associados a matricula
  int *itens;    // vetor de itens a ser alocado dinamicamente
} data_t;

//alocar memória, retornando o ponteiro para a área alocada. A função recebe dois inteiros (mat e n) que representam respectivamente a matricula e o número de itens a serem a ela associados. A função deve então alocar memória capaz de armazenar um vetor de inteiros de tamanho n. 
data_t * newData(int mat, int n){ //20 e 10  
  data_t *ptr;
  ptr = (data_t *) malloc(sizeof(data_t));
  ptr -> matricula = mat;
  ptr -> nitens = n;
  ptr -> itens = (int *) malloc(sizeof(n));
}

//recebe como parâmetro um ponteiro para uma variável do tipo data_t  e um vetor de inteiros. Atribui os valores inteiros ao vetor itens.
void assign(data_t *p, int *v){ //P: ponteiro para var data_t e V os vetores
  p -> itens = v;
}


//Uma função que recebe um ponteiro para o tipo data_t e imprime o conteúdo armazenado na estrutura correspondente.
void print(data_t *p){ 
  for(int i = 0; i < p->nitens; i++){
    printf("\n%d", p->itens[i]);
  }
}

//FUNÇÃO PRINCIPAL
int main() {
  data_t * d = newData(20, 10);
  int v[] = {1,2,3,4,5,6,7,8,9,10};

  if (d) {
    assign(d,v);
    print(d);
  }
}
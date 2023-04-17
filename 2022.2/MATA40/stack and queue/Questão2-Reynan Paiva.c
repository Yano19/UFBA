//BIBLIOTECAS
#include<stdio.h> // PARA O PRINTF, sendo este o responsável por apresentar na tela os valores desejados pelo usuário 
#include<stdlib.h> // PARA O MALLOC, referente a alocação de memória 

// ESTRUTURA DO TIPO point_t
typedef struct point {
    float x, y; //ponto X e ponto Y
} point_t; //nome da estrutura

//ESTRUTURA DO TIPO tabela-p-t
typedef struct tabela_p {

  int n;           // numero de vetores de pontos
  int *k;          // numero de pontos em cada vetor
  point_t ** ptr;  //vetores de pontos: ponteiro de ponteiro
} tabela_p_t;  //nome da estrutura

//ESPAÇO NA MEMÓRIA
void destroi_tabela_pontos(tabela_p_t *ptr) {
//função que libera espaço de memória
  for (int i = 0; i < ptr->n; i++) {  
    //se i < numero de vetores de pontos
      free(ptr->ptr[i]); // desaloca vetor de pontos para posicao i
    }
    free(ptr->k); // desaloca vetor de inteiros k
    free(ptr->ptr); // desaloca tabela 
  }

// FUNÇÃO CRIAR TABELA DE PONTOS
tabela_p_t * cria_tabela_pontos(int n, int * k){
  tabela_p_t *ptr_tab;
  ptr_tab = (tabela_p_t *) malloc(sizeof(tabela_p_t));
  if (ptr_tab == 0) {
    return (tabela_p_t *) NULL;
    }
  ptr_tab -> n = n;
  ptr_tab -> k = (int *) malloc(sizeof(int) * n);
  ptr_tab -> ptr = (point_t **) malloc(sizeof(point_t *) * n);
  if (ptr_tab -> k == 0 || ptr_tab -> ptr == 0) {
    return (tabela_p_t *) NULL;
  }
  for(int i = 0; i<n; i++){

    ptr_tab -> k[i] = k[i];
    ptr_tab -> ptr[i] = (point_t *) malloc(sizeof(point_t) * k[i]);
    if (ptr_tab -> ptr[i] == 0) {
      return (tabela_p_t *) NULL;
    }

    for (int j = 0; j < k[i]; j++) {
      ptr_tab -> ptr[i][j].x = 0; 
      ptr_tab -> ptr[i][j].y = 0;
    }
  }
  return ptr_tab;
}

//IMPRIMIR O RESULTADO

void aboveY(tabela_p_t *ptr, float y) {
  printf("\n Numero de vetores de pontos: %d",ptr -> n);
  printf("\n \t Valor do Parâmetro: %.1f \n", y);
  for (int i = 0; i < ptr -> n; i++) {
    printf("\n \t Endereco do vetor %d: %p", i, ptr -> ptr[i]);
    printf("\n \t Tamanho do vetor %d: %d", i, ptr -> k[i]);
    for (int j = 0; j < ptr -> k[i]; j++) { 
      if(j > y){ //ordenadas = j e parametro = y        
        printf("\n\n \t Ordenada: %d", j);
        printf("\n \t \t ponto[%d][%d] = (%f,%f) \n ",i, j,
	     ptr -> ptr[i][j].x, ptr -> ptr[i][j].y);
        }
      }
    }
  }

//FUNÇÃO PRINCIPAL
int main(){
  tabela_p_t *ptr; 
  int k[] = {1,4,6,7,8}; //Vetor
  ptr = cria_tabela_pontos(5, k); //Tabela de pontos
  if (ptr) {
    aboveY(ptr, 3); //Funão imprimir resultado
    destroi_tabela_pontos(ptr); //Desalocar espaço na memória
  }
}
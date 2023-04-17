#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct cell cell_t;


typedef struct { // cada celula contem 2 ponteiros
    float x, y; //ingressao pela cordenada x ou pela cordenada y
} point_t;


struct cell {
  point_t point; // par ordenado do ponto (x,y)
  cell_t * xnext, * ynext; // ponteiros para construir as listas
};

// Funcao que cria uma nova celula
cell_t *newCell(void) { 
  cell_t *p = malloc( sizeof (cell_t));
  if(p) { // novas celulas teminicialmente  poteiro nulo
    p -> xnext = NULL;
    p -> ynext = NULL;
  } 
  return p;
}

// criar 4 cabeças de listas, uma para cada quadrante.
cell_t ** newList(void) {
  cell_t **q = malloc(4*sizeof(cell_t)); // pontos são distribuídos por quadrante
  if (q) {
  for (int i = 0; i < 4; i++)
    q[i] = newCell(); // cabeça da lista do quadrante i
  }
  return q;
}

//A primeira insere um par ordenado (x,y) (do tipo point_t) em duas listas encadeadas.
void insert(point_t p, cell_t **l) { // 10 20, funcao newlist()
    cell_t *novo = malloc(sizeof(cell_t));

    //QUADRANTE ZERO - xnext     
    if ((p.x > 0) && (p.y > 0)){
        novo->point = p;
        if(l[0]->xnext == NULL){
          l[0]->xnext = novo;
        } else{
          while (l[0]->xnext){
            if((l[0]->xnext->point.x) > (novo->point.x)){
              l[0]->xnext = l[0]->xnext->xnext; 
            }else{
              l[0]->xnext = l[0]->xnext;
            }
          }
        }
    }            

//QUADRANTE ZERO - ynext
    if ((p.x > 0) && (p.x > 0)){
        novo->point = p;
        if(l[0]->ynext == NULL){
          l[0]->ynext = novo;
        } else{
          while (l[0]->ynext){
            if((l[0]->ynext->point.y) > (novo->point.y)){
              l[0]->ynext = l[0]->ynext->ynext; 
            }else{
              l[0]->ynext = l[0]->ynext;
            }
          }
        }
    }   

  //QUADRANTE 1 - xnext
  if((p.x < 0) && (p.y > 0)){
    novo->point = p;
    if (l[1]->xnext == NULL){
      l[1]->xnext = novo;
    } else{
        while (l[1]->xnext){
          if((l[1]->xnext->point.x) < (novo->point.x)){
            l[1]->xnext = l[1]->xnext->xnext;
          } else{
            l[1]->xnext = l[1]->xnext;
          }
        }   
    }
  }

  //QUADRANTE 1 - ynext
  if((p.x < 0) && (p.y > 0)){
    novo->point = p;
    if (l[1]->ynext == NULL){
      l[1]->ynext = novo;
    } else{
        while (l[1]->ynext){
          if((l[1]->xnext->point.x) < (novo->point.x)){
            l[1]->xnext = l[1]->xnext->xnext;
          } else{
            l[1]->xnext = l[1]->xnext;
          }
        }  
    } 
  }

  //QUADRANTE 2 - xnext
  if((p.x < 0) && (p.y < 0)){
    novo->point = p;
    if (l[2]->xnext == NULL){
      l[2]->xnext = novo;
    }else{
      while (l[2]->xnext){
        if((l[2]->xnext->point.x) > (novo->point.x)){
          l[2]->xnext = l[2]->xnext->xnext;
      } else{
        l[2]->xnext = l[2]->xnext;
      }
    } 
  }  
}
  //QUADRANTE 2 - ynext
  if((p.x < 0) && (p.y < 0)){
    novo->point = p;
    if (l[2]->ynext == NULL){
      l[2]->ynext = novo;
    }else{
      while (l[2]->ynext){
        if((l[2]->ynext->point.y) > (novo->point.y)){
          l[2]->ynext = l[2]->ynext->ynext;
      } else{
        l[2]->ynext = l[2]->ynext;
      }
    } 
  }  
}    

  //QUADRANTE 3 - xnext
  if (p.y < 0){
    novo->point = p;
    if(l[3]->xnext == NULL){
      l[3]->xnext = novo;
    }else{
      while(l[3]->xnext){
        if((l[3]->ynext->point.y) < (novo->point.y)){
          l[3]->ynext = l[3]->ynext->ynext;
        } else{
          l[3]->ynext = l[3]->ynext;
        }
      }
    }
  }

  //QUADRANTE 3 - ynext
  if (p.y < 0){
    novo->point = p;
    if(l[3]->ynext == NULL){
      l[3]->ynext = novo;
    }else{
      while(l[3]->ynext){
        if((l[3]->ynext->point.y) < (novo->point.y)){
          l[3]->ynext = l[3]->ynext->ynext;
        } else{
          l[3]->ynext = l[3]->ynext;
        }
      }
    }
  }
}

// imprime o conteúdo destas listas.
void print(cell_t **list){ 
    cell_t *xaux = malloc(sizeof(cell_t));
    cell_t *yaux = malloc(sizeof(cell_t));

    for(int i = 0; i < 4; i++){
      cell_t *xaux = list[i]->xnext;
      cell_t *yaux = list[i]->ynext;

      while((xaux != 0) && (yaux != 0)){// enquanto os dois anterior for diferente de 0
      printf("Quadrante %d:", i);
      printf("\n%f %f\n", list[i]->xnext->point.x, list[i]->xnext->point.y);
      printf("\n%f %f\n", list[i]->ynext->point.x, list[i]->xnext->point.y);
    }

      while((xaux < 0) && (yaux > 0)){// enquanto x menor que 0 e y maior que zero
      printf("Quadrante %d:", i);
      printf("\n(%f,%f)\n", list[i]->xnext->point.x, list[i]->xnext->point.y);
      printf("\n%f %f\n", list[i]->ynext->point.x, list[i]->ynext->point.y);
    }

      while((xaux < 0) && (yaux < 0)){// enquanto x menor que 0 e y menor que 0
      printf("Quadrante %d:", i);
      printf("\n%f %f\n", list[i]->xnext->point.x, list[i]->xnext->point.y);
      printf("\n%f %f\n", list[i]->ynext->point.x, list[i]->ynext->point.y);
    }

      while((xaux != 0) && (yaux < 0)){// y menor que 0 
      printf("Quadrante %d:", i);
      printf("\n%f %f\n", list[i]->xnext->point.x, list[i]->xnext->point.y);
      printf("\n%f %f\n", list[i]->ynext->point.x, list[i]->ynext->point.y);
    }

  } 
}

int main(){ 

  cell_t **list;
  int n;
  point_t p;
  list = newList();

  scanf("%d",&n); //ler tamanho da minha lista

  for(int i = 0; i < n; i++) {
    scanf("%f %f", &p.x,&p.y);
    insert(p,list);    
  }
  print(list);
}
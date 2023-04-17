#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO {
    int dado;
    struct NO *prox;    
} NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
    p -> topo = NULL;
}
//função de empilhamento
void empilha(int dado, PILHA *p){
    NO *ptr = (NO*) malloc (sizeof(NO)); //alocando dinâmicamente
    if (ptr == NULL){ //testando se o nó foi alocado corretamente
        printf("Erro de alocação de nó.\n");
    } else{
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

int desempilha(PILHA *p){
    NO* ptr = p->topo;
    int dado;
    if (ptr == NULL)
    {
        printf("Pilha vazia.\n");
        return 0;
    } else{
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprime(PILHA *p){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("Pilha vazia.\n");
        return;
    }else{
    while(ptr != NULL){
        printf("%d ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("\n");
}
}

int main(){
    PILHA *p1 = (PILHA*) malloc (sizeof(PILHA));
    if (p1 == NULL){
        printf("Erro de alocação de NÓ.\n");
        exit(0);
    }else{
        inicializaPilha(p1);
        empilha(10, p1);
        empilha(20, p1);
        empilha(30, p1);
        imprime(p1);

        printf("Tentando desempilhar - resultado %d\n", desempilha(p1));
        imprime(p1);
        printf("Tentando desempilhar - resultado %d\n", desempilha(p1));
        imprime(p1);
        printf("Tentando desempilhar - resultado %d\n", desempilha(p1));
        desempilha(p1);
    }
}
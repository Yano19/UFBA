#include <stdlib.h>
#include <stdio.h>

struct item
{
    int cod;
};

typedef struct item Item;

struct node{ //tad, direita e esqueda da minha arvore definidos
    Item item;
    struct  node *esqueda, *direita;
};

typedef struct node Node;

Node *initialize(){
    return NULL;
}

Item itemCreate(int cod){
    Item item;
    item.cod = cod;
    return item;
}


Node *inserir(Node *raiz, Item x){
    if (raiz == NULL){
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = x;
        aux->esqueda = NULL;
        aux->direita = NULL;
        return aux;
    }else{
        if(x.cod < raiz->item.cod){
            raiz->esqueda = inserir(raiz->esqueda, x);
        }else if(x.cod > raiz->item.cod){
            raiz->direita = inserir(raiz->direita, x);
        }
    }
    return raiz;
}

void treePrint(Node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->item.cod);
        treePrint(raiz->esqueda);
        treePrint(raiz->direita);
    }
}

void treeFree(Node *raiz){
    if(raiz == NULL){
    treeFree(raiz->esqueda);
    treeFree(raiz->direita);
    free(raiz);
    }
}

Node *treeSearch(Node *raiz, int cod){
    if (raiz != NULL){
       if (raiz->item.cod == cod){
        return raiz;
       }else{
        if(cod > raiz->item.cod){
            return treeSearch(raiz->direita, cod);
        }else{
            return treeSearch(raiz->esqueda, cod);
        }
       }
       
    }
}

    int main(){
    Node *raiz = initialize();
    raiz = inserir(raiz, itemCreate(10));
    raiz = inserir(raiz, itemCreate(15));
    raiz = inserir(raiz, itemCreate(20));
    raiz = inserir(raiz, itemCreate(12));
    raiz = inserir(raiz, itemCreate(5));
    treePrint(raiz);
    Node *tpm = treeSearch(raiz, 11);
    if(tpm == NULL){
        printf("Elemento nao encontrado\n");
    }else{
        printf("Elemento encontrado\n");
    }
    printf("\n");
    treeFree(raiz);
    return 0;
}
    
/*


*/
//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define rat_i 0
#define rat_j 0
#define cheese 19
#define cheese 19



typedef struct _no{//nodo para locomoção e armazenamento caminho do labrinto
	int x;
	int y;
	int dir;    
}no;

typedef struct stack{
    int top;
    int size;
    no **array;
} stack;

stack *create_stack(int size); //criar pilha

void push(stack *p, no *elem); //add no a pilha

no *pop(stack *p); //eliminar ultimo elemento

int empty_stack(stack *p); //verifica se pilha está vazia

int full_stack(stack *p); //virifica se a pilha está cheia

void destroy_Stack(stack *p); //verifica se a pilha esta destruida

no *top(stack *p); //qual elemento esta no topp

int canmazebesolved(int **maze, int **visited, int size){
    int i = rat_i, j = rat_j;
    stack* positionStack = create_stack(size * size);

    no *tempNo = (no*)malloc(sizeof(no));
    tempNo->x = i;
    tempNo->y = j;
    tempNo->dir = 0;

    push(positionStack, tempNo); //add new stack

    while (!empty_stack(positionStack))
    {
        usleep(10 * 100); //tempo de rastro do rato
        tempNo = top(positionStack);
        int direction = tempNo->dir;
        i = tempNo->x;
        j = tempNo->y;

        tempNo->dir++;
        pop(positionStack);
        push(positionStack, tempNo);

        system("clear");
        printf("pisocao rato: ("%d x %d")\n", i, j);
        printMaze(visited, size);

        //se posicao do rato dor encontrada
    if (i == cheese && j == cheese)
    {
        visited[i][j] = 0;

        //destroi pilha
        system("clear");
        destroy_Stack(positionStack);
        return 1;
    }
 //verifica todas as posições com base na direçaõ do rato
    switch (direction)
    {
        //posicao acima do rato
    case 0:
        if(i - 1 >= 0 && maze[i -1][j] && visited[i - 1][j])
        {
            no *newnNo = (no*)malloc(sizeof(no));
            newnNo->x = i - 1;
            newnNo->y = j;
            newnNo->dir = 0;

            visited[i-1][j] = 0;
            push(positionStack, newnNo);
        }
        break;
        case 1:
        if(i - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1])
        {
            no *newnNo = (no*)malloc(sizeof(no));
            newnNo->x = i;
            newnNo->y = j - 1;
            newnNo->dir = 0;

            visited[i-1][j] = 0;
            push(positionStack, newnNo);
        }
        break;
        case 1:
        if(j - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1])
        {
            no *newnNo = (no*)malloc(sizeof(no));
            newnNo->x = i;
            newnNo->y = j - 1;
            newnNo->dir = 0;

            visited[i][j - 1] = 0;
            push(positionStack, newnNo);
        }
        break;
        case 2:
        if(i + 1 >= 0 && maze[i + 1][j] && visited[i + 1][j])
        {
            no *newnNo = (no*)malloc(sizeof(no));
            newnNo->x = i + 1;
            newnNo->y = j;
            newnNo->dir = 0;

            visited[i + 1][j] = 0;
            push(positionStack, newnNo);
        }
        break;

        case 3:
        if(j + 1 >= 0 && maze[i][j + 1] && visited[i][j + 1])
        {
            no *newnNo = (no*)malloc(sizeof(no));
            newnNo->x = i;
            newnNo->y = j + 1;
            newnNo->dir = 0;

            visited[i][j + 1] = 0;
            push(positionStack, newnNo);
        }
        break;
    
        default:
        visited[tempNo->x][tempNo->y] = 1;
        free(pop(positionStack));
    }
    
    destroy_Stack(positionStack);
    return 0;

    //funcao para prencher a matriz com 1
    void fillwithtrue(int *array, int size){
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; i < size; ++j)
            {
                array[i][j] = 1;
            }
            
        }
        
    }
    //funcao para imprimir labirinto
    void printMaze(int **array, int size){

    }
}

int main(){
    
}
    
























/*
int funcaoBusca(char map[h][w], int i, int){
        map[i][j] = 'v';
        if (map[i][j+1] == "1"){
            j++;
        }
    }

char map[h][w] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


int main()  
{
    for (char i = 0; i < h; i++){
        for (char j = 0; j < w; j++){
             if(map[i][j]) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}*/
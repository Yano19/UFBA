#include <stdlib.h>
#include <stdio.h>

void ler(char f[])
{
    FILE *file = fopen(f, "r");
    char texto[500];
    if (file == NULL)
    {
        printf("\nArquivo não pode ser aberto!\n");
        getchar();
        exit(0);
    }
    else
    {
        while(!feof(file)){
        if(fgets(texto, 500, file))
            printf("%s", texto);
        }
        fclose(file);
    }
}

int main()
{
    char nome[] = ("input2.txt");
    ler(nome);
    return 0;
}

// listar conteudo do arquivo txt linha por linha
// listar conteudo do arquivo por caractere TXT
/*
void txt_criar(){
    arq = fopen("arquivo.txt", "w");
    fprintf(arq, %s\n\n"," --- Arquivo.txt Criado ----");
    fclose(arq);
}

void txt-incluir(){
    arq = fopen("arquivo.txt", "a");
    do{
        gets(texto);
        if(strlen(texto)>2)
        fprintf(arq, %s\n, texto);
    } while (strlen(texto) > 2);
    fclose(arq);
}

void txt_ler(){
    arq = fopen("arquivo.txt", "r");
    while(!feof(arq)){
        fgets(texto, 255, arq);
        printf(%s, texto);
    }
    fclose(arq);
}*/

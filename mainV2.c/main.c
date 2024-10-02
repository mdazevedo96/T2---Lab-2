#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "printMat.h"

void le_tamanho(int* l, int* c)
{
    printf("INSIRA O TAMANHO DA MATRIZ(LINHA  COLUNA): ");
    scanf(" %d %d", l, c);
    while((getchar()) != '\n');
}

char ** inicia_matriz(int l, int c)
{
    char ** matriz = (char **) malloc (l * sizeof(char*));
    if (matriz == NULL){
        printf("ERRO DE ALOCACAO");
        exit(1);
    }
    for(int i=0; i<l; i++){
        matriz[i] = (char*) malloc(c * sizeof(char));

        if(matriz[i] == NULL){
            printf("ERRO NA ALOCACAO");
            exit(1);
        }
    }
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            matriz[i][j] = '\0';
        }
    }
    return matriz;
}

int preenche_matriz(char*** mat, int l, int c)
{
    int k = 0;
    char aux[800];

    printf("DIGITE UM TEXTO: ");
    fgets(aux, sizeof(aux), stdin);

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            while(aux[k] == ' ') {k += 1;}
            if(aux[k] == '\n' || aux[k] == '\0') {return 0;}
            (*mat)[i][j] = toupper(aux[k]);
            k += 1;
        }
    }
    return 1;
}

void libera_matriz(char** mat, int l)
{
    for (int i = 0; i < l; i++) {
        free(mat[i]);
    }
    free(mat);
}

/*só falta essa, separar em mais funcoes. E depois que estiver tudo rodando, criar funcoes.c e funcoes.h*/
void busca_palavras(){}

int main()
{
    int m, n;

    le_tamanho(&m ,&n);

    char** matriz = inicia_matriz(m, n);

    preenche_matriz(&matriz, m, n);

    print_mat(matriz, m, n);

    libera_matriz(matriz, m);

    return 0;
}

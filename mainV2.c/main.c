#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "printMat.h"
#include "funcoes.h"

int le_palavra(char* p, int* tam)
{
    printf("\nDIGITE A PALAVRA QUE DESEJA PROCURAR: ");
    scanf(" %s", p);
    for(int i=0; p[i] != '\0'; i++)
        p[i] = toupper(p[i]);
    *tam = strlen(p);
}

int horizontal(char** mat, int l, int c, char* palavra, int tam)
{
    for(int i=0; i<l; i++){
        char* p = strstr(mat[i], palavra);
        if(p != NULL){
            int ini = (p - mat[i]) + 1;
            int fim = ini + tam - 1;
            printf("\nPALAVRA: %s\nOCORRENCIA: HORIZONTAL DIRETA", palavra);
            printf("\nPOSICAO DA PALAVRA: INÍCIO[%d,%d] - FIM[%d,%d].\n", i+1, ini, i+1, fim);
            return 0;
        }
    }
    printf("\nPALAVRA NAO ENCONTRADA\n");
}
/*
int vertical(char** mat, int l, int c, char* palavra, int tam)
{
    for(int i=0; i<c; i++){
        for(int j=0; j<l; j++){
            if(mat[i][j] == palavra[j]){

            }
        }
    }
    printf("\nPALAVRA NAO ENCONTRADA\n");
}
*/
void busca_palavras(char** mat, int lin, int col)
{
    char palavra[50];
    int resposta, tam;
    do{
        le_palavra(palavra, &tam);
        horizontal(mat, lin, col, palavra, tam);
//        vertical(mat, lin, col, palavra, tam);
//        diag_prim(mat, lin, col, palavra, tam);
//        diag_sec(mat, lin, col, palavra, tam);
        printf("\nCONTINUAR PROCURANDO? 1-SIM   0-NAO\t");
        scanf("%d", &resposta);
        while((getchar()) != '\n');
    }while(resposta != 0);
}

int main()
{
    int l, c;

    le_tamanho(&l ,&c);

    char** matriz = inicia_matriz(l, c);

    preenche_matriz(&matriz, l, c);

    print_mat(matriz, l, c);

    busca_palavras(matriz, l, c);

    libera_matriz(matriz, l);

    return 0;
}

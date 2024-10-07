#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "printMat.h"
#include "funcoes.h"

int horizontal(char** mat, int l, int c, char* buscada)
{
    char* p;
    int ini, fim, tam = strlen(buscada);
    for(int i=0; i<l; i++){
        p = strstr(mat[i], buscada);
        if(p != NULL){
            ini = (p - mat[i]) + 1;
            fim = ini + tam;
            printf("\nPALAVRA: %s\nOCORRENCIA: HORIZONTAL DIRETA", buscada);
            printf("\nPOSICAO DA PALAVRA: INÍCIO[%d,%d] - FIM[%d,%d].\n", i+1, ini, i+1, fim);
            return 0;
        }
    }
    printf("\nPALAVRA NAO ENCONTRADA\n");
}

void busca_palavras(char** mat, int lin, int col)
{
    char palavra[50];
    int resposta = 1;
    while(resposta != 0){
        printf("\nDIGITE A PALAVRA QUE DESEJA PROCURAR: ");
        fgets(palavra, 50, stdin);

        palavra[strcspn(palavra, "\n")] = '\0';

        for(int i=0; palavra[i] != '\0'; i++)
            palavra[i] = toupper(palavra[i]);

        horizontal(mat, lin, col, palavra);
//    vertical(mat, lin, col, palavra);
//    diag_prim(mat, lin, col, palavra);
//    diag_sec(mat, lin, col, palavra);
        printf("\nCONTINUAR PROCURANDO? 1-SIM   0-NAO\t");
        scanf("%d", &resposta);
        while((getchar()) != '\n');
    }
}

int main()
{
    int m, n;

    le_tamanho(&m ,&n);

    char** matriz = inicia_matriz(m, n);

    preenche_matriz(&matriz, m, n);

    print_mat(matriz, m, n);

    busca_palavras(matriz, m, n);

    libera_matriz(matriz, m);

    return 0;
}

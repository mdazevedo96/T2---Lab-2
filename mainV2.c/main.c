#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printMat.h"

void leTamanho(int* m, int* n)
{
    printf("INSIRA O TAMANHO DA MATRIZ(LINHA x COLUNA): ");
    scanf(" %d %d", m, n);
    while((getchar()) != '\n');
}

char ** inicia_matriz(int m, int n)
{
    char ** matriz = NULL;
    matriz = (char **) malloc (m * sizeof(char*));
    if (matriz == NULL){
        printf("Erro de alocacao");
        exit(1);
    }
    for(int i=0; i< n; i++){
        matriz[i] = (char*) malloc(n * sizeof(char));

        if(matriz[i] == NULL){
            printf("Erro na alocacao");
            exit(1);
        }
        for(int j=0; j<n;j++){
            matriz[i][j] = '\0';
        }
    }
    return matriz;
}

void preencheMatriz(char*** mat, int m, int n)
{
    int k = 0;
    char aux[500];

    printf("DIGITE UM TEXTO: ");
    fgets(aux, sizeof(aux), stdin);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if((aux[k] == ' ') || (aux[k] == '\n')) {k += 1;}
            (*mat)[i][j] = aux[k];
            k +=1;
        }
    }
}

/*
void imprimeMatriz(char** mat, int m, int n)
{
//adicionei o if e else pq dps que terminava os chars da matriz, por conta do '\n' no stdin (eu creio), ele jogava pra baixo o restante dos [] vazios.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] != '\0'){
                printf("[%c]", mat[i][j]);
            }else {printf("[ ]");}
        }
        printf("\n");
    }
}
*/


void liberaMatriz(char** matriz, int m)
{
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/*buscaPalavras() (separa essa aqui em mais funcoes)*/

int main()
{
    int m, n;

    leTamanho(&m ,&n);

    char** matriz = inicia_matriz(m, n);

    preencheMatriz(&matriz, m, n);
    //estava fazendo uma funcao pra imprimir matriz usando ┃ ━; como já estava no processo, terminei de criar, aí deixo a teu critério qual tu quer usar.
//    print_mat(matriz, m, n); //só chamar essa que ela imprime, mas tem q ter o printMat.h

    liberaMatriz(matriz, m);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

void preencheMatriz(int m, int n){
    char** mat = (char**) malloc(m*sizeof(char*));
    if(mat == NULL){
        printf("Erro na alocacao");
        exit(1);
    }else{
        for(int i=0; i<m; i++){
            mat[i] = (char*)malloc(n*sizeof(char));
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                printf("Digite a palavra: \n");
                scanf("%s", &mat[i][j]);
            }
        }

    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

void alocaMatriz(int m, n){
    char* mat = (char*) malloc(m*n*sizeof(char));

    if(mat == NULL){
        printf("Erro na alocacao");
        exit(1);
    }else{

    }
}

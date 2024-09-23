#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    int m,n = 0;
    printf("Digite o tamanho da matriz [m][n]: \n");
    scanf("%d %d", &m, &n);
    alocaMatriz(m,n);
}

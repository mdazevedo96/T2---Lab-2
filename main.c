#include <stdio.h>
#include <stdlib.h>


char ** inicia_matriz(int m, int n){
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
            matriz[i][j] = 'p';
        }
    }
    return matriz;
}

void imprime_matriz(char** matriz, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m = 5;
    int n = 5;
    char** matriz = inicia_matriz(m,n);
    imprime_matriz(matriz,m,n);
    return 0;
}

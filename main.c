#include <stdio.h>
#include <stdlib.h>

void alocaMatriz(char*** matriz, int m, int n) {
    *matriz = (char**) malloc(m * sizeof(char*));
    if (*matriz == NULL) {
        printf("Erro na alocacao");
        exit(1);
    } else {
        for (int i = 0; i < m; i++) {
            (*matriz)[i] = (char*) malloc(n * sizeof(char));
            if ((*matriz)[i] == NULL) {
                printf("Erro na alocacao");
                exit(1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*matriz)[i][j] = '\0';
            }
        }
    }
}

int main() {
    char** matriz;
    int m = 3, n = 4;

    alocaMatriz(&matriz, m, n);

    matriz[0][0] = 'A';
    matriz[1][1] = 'B';
    matriz[2][2] = 'C';

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

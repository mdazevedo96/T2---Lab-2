#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "printMat.h"
#include "funcoes.h"

/*só falta essa, separar em mais funcoes. E depois que estiver tudo rodando, adicionar em funcoes.c e funcoes.h*/
void busca_palavras()
/*??? Porvavelmente há um jeito melhor de fazer essa parte*/
{
    char palavras[800];
    printf("DIGITE AS PALAVRAS QUE DESEJA PROCURAR NO CAÇA-PALAVRA: ");
    fgets(palavras, sizeof(palavras), stdin);
    printf("%s", palavras);
}

int main()
{
    int m, n;

    le_tamanho(&m ,&n);

    char** matriz = inicia_matriz(m, n);

    preenche_matriz(&matriz, m, n);

    print_mat(matriz, m, n);

    busca_palavras();

    libera_matriz(matriz, m);

    return 0;
}

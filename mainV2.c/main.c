#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "printMat.h"
#include "funcoes.h"

/*só falta essa, separar em mais funcoes. E depois que estiver tudo rodando, adicionar em funcoes.c e funcoes.h*/
/*??? Porvavelmente há um jeito melhor de fazer essa parte*/
void busca_palavras()
{
    char palavras[800];
    char buscada[50];
    int tam, t, nvTam;

    printf("DIGITE AS PALAVRAS QUE DESEJA PROCURAR NO CAÇA-PALAVRA: ");
    fgets(palavras, sizeof(palavras), stdin);

    tam = strlen(palavras);
    palavras[tam-1] = '\0';

    printf("\nstring palavras: %s. Tam string: %d. Ultimo char(deve ser vazio): (%c)", palavras, tam, palavras[tam-1]);

//separa a primeira palavra da string 'palavras' pra poder buscar a mesma;
    for(int i = 0; palavras[i] != ' '; i++){
        buscada[i] = palavras[i];
        if(palavras[i+1] == ' '){
            buscada[i+1] = '\0';
            t = strlen(buscada)+1;
        }
    }

    printf("\n%s. tam: %d", buscada, t);
    nvTam = tam-t;

//elimina palavra ja buscada da string 'palavras';
    printf("\n%c", palavras[t]);

    for(int i=0; i<nvTam; i++){
        palavras[i] = palavras[t];
        t += 1;
    }
    palavras[nvTam] = '\0';

    printf("\nstring palavras:%s. Tam string: %d. Ultimo char(deve ser vazio): (%c)", palavras, nvTam, palavras[nvTam-1]);
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

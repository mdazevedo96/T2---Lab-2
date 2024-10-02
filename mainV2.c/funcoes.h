#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void le_tamanho(int* l, int* c);

char ** inicia_matriz(int l, int c);

int preenche_matriz(char*** mat, int l, int c);

void libera_matriz(char** mat, int l);

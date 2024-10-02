#include <stdio.h>
#include <stdlib.h>
#include "printMat.h"

void print_n_lin(int i)
{
    printf("%2d ┃", i+1);
}

void print_n_col(int c)
{
    printf("\n      ");
    for(int x = 0; x < c; x++)
    {
        if(x>=10)
            printf("  %d  ", x+1);
        else
            printf("  %d   ", x+1);
    }
}

void print_chars(char** m, int c, int i)
{
    for(int j = 0; j < c; j++)
    {
        if(m[i][j] == '\0')
            printf("     ┃");
        else
            printf("  %c  ┃", m[i][j]);
    }
}

void print_bar(int c)
{
    printf("\n     ");
    for(int x = 0; x < c; x++)
    {
        printf("┃━━━━━");
        if(x == (c-1))
            printf("┃\n  ");
    }
}

void print_mat(char** mat, int lin, int col)
{
    printf("\n");
    print_n_col(col);
    for(int i = 0; i < lin; i++)
    {
        print_bar(col);
        print_n_lin(i);
        print_chars(mat, col, i);
    }
    print_bar(col);
    printf("\n");
}

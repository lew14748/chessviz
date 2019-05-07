#include "board_print_plain.h"
#include <stdio.h>
extern char desk[8][8];
void printboard()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            printf("%c", desk[i][j]);
        printf("\n");
    }
    return;
}

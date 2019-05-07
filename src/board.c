#include "board.h"
#include <stdio.h>
#include <string.h>

extern char desk[8][8];
int X1, X2, Y1, Y2;

void scan(int side)
{
    char input[7] = "NULL";
    while (1) {
        while (1) {
            fgets(input, 7, stdin);
            if (ctoi(input)) {
                break;
            }
            printf("Введите заново:");
        }
        if (side == 1) {
            if (white() == 1) {
                break;
            } else {
                printf("Введите заново:");
            }
        }
        if (side == 2) {
            if (black() == 1) {
                break;
            } else {
                printf("Введите заново:");
            }
        }
    }
}

int ctoi(char input[7])
{
    X1 = (int)input[0] - 'A';
    Y1 = (int)input[1] - '1';
    X2 = (int)input[3] - 'A';
    Y2 = (int)input[4] - '1';
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8)
        && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}

int white()
{
    if (desk[Y1][X1] > 64 && desk[Y1][X1] < 73) {
        return 0; 
    }
    switch (desk[Y1][X1]) {
    case 'P':
        if ((desk[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0)
            && (Y2 - Y1 < 3)) {
            return 1; 
        }
        if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y2 - Y1 == 1)) {
            return 1; 
        }
        if ((desk[Y2][X2] > 'a' && desk[Y2][X2] < 's')
            && ((X2 - X1 == 1) || (X2 - X1 == -1)) && (Y2 - Y1 == 1)) {
            return 1; 
        }
    }
    return 0;
}
int black()
{
    if (desk[Y1][X1] > 96 && desk[Y1][X1] < 105) {
        return 0;
    }
    switch (desk[Y1][X1]) {
    case 'p':
        if ((desk[Y2][X2] == ' ') && (Y1 == 6) && (X1 == X2) && (Y1 - Y2 > 0)
            && (Y1 - Y2 < 3)) {
            return 1; 
        }
        if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y1 - Y2 == 1)) {
            return 1; 
        }
        if ((desk[Y2][X2] < 'S' && desk[Y2][X2] > 'A')
            && ((X1 - X2 == 1) || (X1 - X2 == -1)) && (Y1 - Y2 == 1)) {
            return 1;
        }
    }
    return 0;
}
void move()
{
    desk[Y2][X2] = desk[Y1][X1];
    desk[Y1][X1] = ' ';
}

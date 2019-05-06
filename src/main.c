#include<stdio.h>
#include"board.h"
#include "board_print_plain.h"

char input[7];
int X1, X2, Y1, Y2;
char desk[8][8] = {{'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};


int main()
{
  printboard();
  
  for(;;)
{
scan(1);
move();
printboard();

scan(2);
move();
printboard();
break;
}

return 0;
}

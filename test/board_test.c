#include "../ctest_library/ctest.h"
#include "../src/board.h"
#include "../src/board_print_plain.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int X1, X2, Y1, Y2;
char desk[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char input[7];

CTEST(inputdata, chartointer)
{
    strcpy(input, "E2fE4"); // incorrect format
    int inc1 = ctoi(input);

    strcpy(input, "E2xE4"); // chop-chop
    int inc2 = ctoi(input);

    strcpy(input, "E2-E4"); // sprint
    int c3 = ctoi(input);

    strcpy(input, "E2-E9"); // out of field
    int inc4 = ctoi(input);

    strcpy(input, "GOOD DAY, SIR!"); // rubbish
    int inc5 = ctoi(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, inc1);
    ASSERT_EQUAL(exp2, inc2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, inc4);
    ASSERT_EQUAL(exp5, inc5);
}

CTEST(moving, movepawn) // pawn test
{
    strcpy(input, "D7-D6"); // First stroll
    ctoi(input);
    desk[Y1][X1] = 'p';
    int c1 = black();

    strcpy(input, "D7-D5"); // First rush
    ctoi(input);
    int c2 = black();

    desk[Y1][X1] = ' ';

    strcpy(input, "D6-D4"); // Rush in the middle
    ctoi(input);
    desk[Y1][X1] = 'p';
    int c3 = black();

    strcpy(input, "D6-C5"); // like chopping
    ctoi(input);
    int c4 = black();

    strcpy(input, "D6-D7"); // backwards
    ctoi(input);
    int c5 = black();

    strcpy(input, "D6xC5"); // chopping
    ctoi(input);
    desk[Y2][X2] = 'P';
    int c6 = black();

    desk[Y2][X2] = ' ';
    desk[Y1][X1] = ' ';

    strcpy(input, "D7-D5"); // overstepping
    ctoi(input);
    desk[Y1][X1] = 'P';
    desk[Y1 + 1][X1] = 'P';
    int c7 = black();

    desk[Y1][X1] = ' ';
    desk[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moverook) // rook test
{
    strcpy(input, "D4-D7"); // ahead
    ctoi(input);
    desk[Y1][X1] = 'R';
    int c1 = white();

    strcpy(input, "D4-D2"); // backwards
    ctoi(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // right
    ctoi(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // left
    ctoi(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // diagonal
    ctoi(input);
    int c5 = white();

    strcpy(input, "D4xD5"); // chop-chop
    ctoi(input);
    desk[Y2][X2] = 'r';
    int c6 = white();

    strcpy(input, "D4-D6"); // overstepping
    ctoi(input);
    int c7 = white();

    desk[Y1][X1] = ' ';
    desk[Y2 - 1][X2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

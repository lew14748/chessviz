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

    strcpy(input, "GOO"); // rubbish
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

CTEST(moving, moveknight) // Тест коня
{
    strcpy(input, "D4-D7"); // Ход вперед
    ctoi(input);
    desk[Y1][X1] = 'N';
    int c1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    ctoi(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    ctoi(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    ctoi(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    ctoi(input);
    int c5 = white();

    strcpy(input, "D4-C6"); // Ход Г вверх влево
    ctoi(input);
    int c61 = white();

    strcpy(input, "D4-E6"); // Ход Г вверх вправо
    ctoi(input);
    int c62 = white();

    strcpy(input, "D4-F5"); // Ход Г вправо вверх
    ctoi(input);
    int c63 = white();

    strcpy(input, "D4-F3"); // Ход Г вправо вниз
    ctoi(input);
    int c64 = white();

    strcpy(input, "D4-E2"); // Ход Г вниз вправо
    ctoi(input);
    int c65 = white();

    strcpy(input, "D4-C2"); // Ход Г вниз влево
    ctoi(input);
    int c66 = white();

    strcpy(input, "D4-B5"); // Ход Г влево вверх
    ctoi(input);
    int c67 = white();

    strcpy(input, "D4-B3"); // Ход Г влево вниз
    ctoi(input);
    int c68 = white();

    strcpy(input, "D4xE6"); // Ход через фигуру и взятие
    ctoi(input);
    desk[X1 + 1][Y1] = 'p';
    desk[Y2][X2] = 'n';
    int c7 = white();

    desk[Y1][X1] = ' ';
    desk[X1 + 1][Y1] = ' ';
    desk[Y2][X2] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp61 = 1;
    const int exp62 = 1;
    const int exp63 = 1;
    const int exp64 = 1;
    const int exp65 = 1;
    const int exp66 = 1;
    const int exp67 = 1;
    const int exp68 = 1;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp61, c61);
    ASSERT_EQUAL(exp62, c62);
    ASSERT_EQUAL(exp63, c63);
    ASSERT_EQUAL(exp64, c64);
    ASSERT_EQUAL(exp65, c65);
    ASSERT_EQUAL(exp66, c66);
    ASSERT_EQUAL(exp67, c67);
    ASSERT_EQUAL(exp68, c68);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, movebishop) // Тест слона
{
    strcpy(input, "D4-D7"); // Ход вперед
    ctoi(input);
    desk[Y1][X1] = 'B';
    int c1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    ctoi(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    ctoi(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    ctoi(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали вверх вправо
    ctoi(input);
    int c51 = white();

    strcpy(input, "D4-B6"); // Ход по диагонали вверх влево
    ctoi(input);
    int c52 = white();

    strcpy(input, "D4-F2"); // Ход по диагонали вниз вправо
    ctoi(input);
    int c53 = white();

    strcpy(input, "D4xB2"); // Ход по диагонали вверх вправо и взятие
    ctoi(input);
    desk[Y2][X2] = 'p';
    int c54 = white();

    desk[Y2][X2] = ' ';

    strcpy(input, "D4-F6"); // Ход по диагонали вниз вправо через фигуру
    ctoi(input);
    desk[Y2 - 1][X2 - 1] = 'p';
    int c6 = white();

    desk[Y1][X1] = ' ';
    desk[Y2 - 1][X2 - 1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp51 = 1;
    const int exp52 = 1;
    const int exp53 = 1;
    const int exp54 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp51, c51);
    ASSERT_EQUAL(exp52, c52);
    ASSERT_EQUAL(exp53, c53);
    ASSERT_EQUAL(exp54, c54);
    ASSERT_EQUAL(exp6, c6);
}

CTEST(moving, moveking) // Тест короля
{
    strcpy(input, "D4-D5"); // Ход вверх
    ctoi(input);
    desk[Y1][X1] = 'K';
    int c1 = white();

    strcpy(input, "D4-D3"); // Ход вниз
    ctoi(input);
    int c2 = white();

    strcpy(input, "D4-C4"); // Ход влево
    ctoi(input);
    int c3 = white();

    strcpy(input, "D4-E4"); // Ход вправо
    ctoi(input);
    int c4 = white();

    strcpy(input, "D4-E5"); // Ход вверх вправо
    ctoi(input);
    int c5 = white();

    strcpy(input, "D4-C5"); // Ход вверх влево
    ctoi(input);
    int c6 = white();

    strcpy(input, "D4-E3"); // Ход вниз вправо
    ctoi(input);
    int c7 = white();

    strcpy(input, "D4xC3"); // Ход вниз влево и взятие
    ctoi(input);
    desk[Y2][X2] = 'p';
    int c8 = white();

    desk[Y2][X2] = ' ';

    strcpy(input, "D4-D6"); // Ход вверх на 2 клетки
    ctoi(input);
    int c9 = white();

    strcpy(input, "D4-F2"); // Ход вниз вправо на 2 клетки
    ctoi(input);
    int c10 = white();

    desk[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}

CTEST(moving, movequeen) // Тест ферзя
{
    strcpy(input, "D4-D7"); // Ход вверх
    ctoi(input);
    desk[Y1][X1] = 'Q';
    int c1 = white();

    strcpy(input, "D4-D1"); // Ход вниз
    ctoi(input);
    int c2 = white();

    strcpy(input, "D4-A4"); // Ход влево
    ctoi(input);
    int c3 = white();

    strcpy(input, "D4-G4"); // Ход вправо
    ctoi(input);
    int c4 = white();

    strcpy(input, "D4-G7"); // Ход по диагонали вверх вправо
    ctoi(input);
    int c5 = white();

    strcpy(input, "D4-A7"); // Ход по диагонали вверх влево
    ctoi(input);
    int c6 = white();

    strcpy(input, "D4-A1"); // Ход по диагонали вних влево
    ctoi(input);
    int c7 = white();

    strcpy(input, "D4xG1"); // Ход по диагонали вниз вправо и взятие
    ctoi(input);
    desk[Y2][X2] = 'p';
    int c8 = white();

    desk[Y2][X2] = ' ';

    strcpy(input, "D4-G7"); // Ход по диагонали вверх вправо через фигуру
    ctoi(input);
    desk[Y2 - 1][X2 - 1] = 'p';
    int c9 = white();

    desk[Y2 - 1][X2 - 1] = ' ';

    strcpy(input, "D4-F7"); // Ход Г по диагонали вверх вправо
    ctoi(input);
    int c10 = white();

    desk[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}
CTEST(signs ,sign)
{
    strcpy(input, "E2fE4"); // Ввод неправильного формата
    int c1 = ctoi(input);

    strcpy(input, "E2xE4"); // Ход взятия
    int c2 = ctoi(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int c3 = ctoi(input);

    strcpy(input, "E2#E9"); // Неправилный знак
    int c4 = ctoi(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

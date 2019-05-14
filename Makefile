all: bin/chessviz bin/test

bin/chessviz: build/main.o build/board_print_plain.o build/board.o
	gcc -Wall -Werror build/main.o build/board_print_plain.o build/board.o -o bin/chessviz

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

bin/test: build/test_main.o build/board_test.o build/src/board.o build/board_print_plain.o
	gcc -Wall -Werror build/test_main.o build/board_test.o build/board.o build/board_print_plain.o -o bin/test

build/main.o: build/main.c
	gcc -I ctest_library -Wall -Werror -c test/main.c -o build/test_main.o

build/board_test.o: build/board_test.c
	gcc -I ctest_library -Wall -Werror -c test/board_test.c -o build/board_test.o

.PHONY: clean

clean:
	rm -rf build/*.o

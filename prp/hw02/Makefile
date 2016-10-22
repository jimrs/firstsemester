CC=clang
CFLAGS+= -pedantic -Wall -Werror -std=c99 -O3

program: main.c 
	${CC} ${CFLAGS} main.c -o program

check: program
	./program < data/pub01.in > data/1.out
	./program < data/pub02.in > data/2.out
	./program < data/pub03.in > data/3.out
	diff data/pub01.out data/1.out
	diff data/pub02.out data/2.out
	diff data/pub03.out data/3.out

zip:
	zip hw02-us.zip main.c

clean:
	rm -f *.o
	rm -f program
	rm -f hw02-us.zip

CC=gcc
CFLAGS=-O0 -Wall -ggdb
CLEAN=prog prog.o evil.so load.o

all: prog evil.so

prog: prog.o
	${CC} ${CFLAGS} -o prog prog.o

prog.o: prog.c
	${CC} ${CFLAGS} -c prog.c

evil.so: load.o
	${CC} load.o -ldl -shared -o evil.so

load.o: load.c
	${CC} -c -fPIC -ldl load.c -o load.o

clean:
	rm ${CLEAN}

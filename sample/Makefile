CC=gcc
CFLAGS=-std=c99

all:
	mkdir -p bin
	${CC} ${CFLAGS} ../dbug/dbug.c -c -o bin/dbug.o
	${CC} ${CFLAGS} Sample.c -c -o bin/Sample.o
	${CC} ${CFLAGS} bin/dbug.o bin/Sample.o -o bin/sample

clean:
	rm -rf bin/*


test: all
	export DBUG_OPTS="d:t:o:L:";bin/sample

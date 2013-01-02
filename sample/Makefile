CC=gcc
CFLAGS=

all:
	mkdir -p bin
	${CC} ${CFLAGS} ../dbug/dbug.c -c -o bin/dbug.o
	${CC} ${CFLAGS} Sample.c -c -o bin/Sample.o
	${CC} ${CFLAGS} bin/dbug.o bin/Sample.o -o bin/sample

clean:
	rm -rf bin/*


test: clean all
	cd bin;export DBUG_OPTS="d:t:o:L:i:n:N:P:g"; sample

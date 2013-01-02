ifeq ($(CC),gcc)
    CFLAGS+=-std=c99
    CFLAGS89=-std=c89
endif

ifeq ($(CC),xlc)
    CFLAGS+=-qlanglvl=stdc99
    CFLAGS89=-qlanglvl=stdc89
endif

all:
	mkdir -p bin
	$(CC) $(CFLAGS) ../dbug/dbug.c -c -o bin/dbug.o
	$(CC) $(CFLAGS) Sample.c -c -o bin/Sample.o
	$(CC) $(CFLAGS) bin/dbug.o bin/Sample.o -o bin/sample
	$(CC) $(CFLAGS89) ../dbug/dbug.c -c -o bin/dbug89.o
	$(CC) $(CFLAGS89) Sample89.c -c -o bin/Sample89.o
	$(CC) $(CFLAGS89) bin/dbug89.o bin/Sample89.o -o bin/sample89

clean:
	rm -rf bin/*


test: clean all
	cd bin;echo "------C99------"; export DBUG_OPTS="d:t:o:L:i:n:N:P:g"; ./sample
	cd bin;echo "------C89------"; export DBUG_OPTS="d:t:o:L:i:n:N:P:g"; ./sample89

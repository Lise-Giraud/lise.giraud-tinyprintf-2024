$CC=gcc
$CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
$LDFLAGS=-lcriterion -fsanitize=address

all: tinyprintf check

tinyprintf: tinyprintf.o
	$(CC) -o tinyprintf tinyprintf.o

tinyprintf.o: tinyprintf.c
	$(CC) $(CFLAGS) -c -o tinyprintf.o src/tinyprintf.c

check: check.o
	$(CC) $(LDFLAGS) -o check tinyprintf.o check.o

check.o: check.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o check.o tests/check.c

clean:
	rm -r *.o

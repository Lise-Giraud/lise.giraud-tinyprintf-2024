$CC=gcc
$CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
$LDFLAGS=-lcriterion -fsanitize=address

tinyprintf: tinyprintf.o
	$(CC) -o tinyprintf tinyprintf.o

tinyprintf.o: src/tinyprintf.c
	$(CC) $(CFLAGS) -c -o tinyprintf.o src/tinyprintf.c

check: check.o tinyprintf
	$(CC) $(LDFLAGS) -c -o check tinyprintf.o check.o

check.o: tests/check.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o check.o tests/check.c

clean:
	rm -r *.o

CC=gcc
CFLAGS=-Wextra -Wall -Werror -std=c99 -pedantic
LDFLAGS=-lcriterion
BINARY=tinyprintf

check:
	$(CC) $(DBFLAGS) $(LDFLAGS) src/tinyprintf.c tests/*.c -o $(BINARY)
	./tinyprintf --verbose

build: src/tinyprintf.o
	$(CC) $(CFLAGS) -o $(BINARY) src/tinyprintf.o

clean:
	rm -f src/tinyprintf.o
	rm -f tinyprintf

src/tinyprintf.o: src/tinyprintf.c
	$(CC) $(CFLAGS) -c -o src/tinyprintf.o src/tinyprintf.c

CC=gcc
CFLAGS=-lm
all: cache.c
	$(CC) -o cache cache.c $(CFLAGS)
clean:
	rm cache

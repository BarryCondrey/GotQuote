#  CC will be the compiler to use.
CC=cc
# CFLAGS will be the
CFLAGS=-c -Wall

all: gotquote

gotquote: gotmain.o quotes.o
	$(CC) gotmain.o quotes.o -o gotquote 

gotmain.o: gotmain.c
	$(CC) $(CFLAGS) gotmain.c

quotes.o: quotes.c
	$(CC) $(CFLAGS) quotes.c

clean:
	rm -rf *o hello

# GNU Makefile

CC = gcc
CFLAGS = -Wall -g

all: stage1exe

stage1exe: driver.c lexer.c
	$(CC) $(CFLAGS) -o stage1exe driver.c lexer.c

clean:
	rm -f stage1exe *.o

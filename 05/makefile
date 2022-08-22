CFLAGS = -Wall -Werror -std=gnu99 -g
CC = gcc

all: matvecRow matvecCol

matvecRow: matvecRow.c matvec.h main.c check_result.o
	$(CC) $(CFLAGS) -o matvecRow matvecRow.c main.c check_result.o

matvecCol: matvecCol.c matvec.h main.c check_result.o
	$(CC) $(CFLAGS) -o matvecCol matvecCol.c main.c check_result.o

.PHONY: clean

clean:
	rm -f matvecRow matvecCol
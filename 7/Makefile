CFLAGS = -Wall -Werror -std=gnu99 -g
CC = gcc

all: main1 main2 main3

main1: BST.c BST.h main1.c check_BST.o
	$(CC) $(CFLAGS) -o main1 BST.c main1.c check_BST.o

main2: remove_redundant.c remove_redundant.h main2.c check_tree.o
	$(CC) $(CFLAGS) -o main2 remove_redundant.c main2.c check_tree.o

main3: balanced_BST.c balanced_BST.h main3.c check_balance.o
	$(CC) $(CFLAGS) -o main3 balanced_BST.c main3.c check_balance.o

.PHONY: clean

clean:
	rm -f main1 main2 main3
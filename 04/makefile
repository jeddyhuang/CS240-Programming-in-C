flags= -Wall -Werror -std=c99 -g
CC= gcc
target= matvec

all: $(target)

matvec.o: matvec.c matvec.h
	$(CC) $(flags) -c matvec.c

MV_main.o: MV_main.c
	$(CC) $(flags) -c MV_main.c

$(target): matvec.o MV_main.o
	$(CC) $(flags) -o matvec matvec.o MV_main.o

clean:
	rm $(target)
CFLAGS = -Wall -Werror -std=gnu99 -g
CC = gcc

CFILES=parity.c

program: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o parity

.PHONY: clean

clean:
	rm -f parity
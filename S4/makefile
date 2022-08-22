CFLAGS = -Wall -Werror -std=gnu99 -g
CC = gcc

CFILES=html_parser.c

program: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o html_parser

.PHONY: clean

clean:
	rm -f html_parser
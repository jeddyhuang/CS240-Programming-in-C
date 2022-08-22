flags = -Wall -Werror -std=c99 -g
CC = gcc
src1 = factorial_recur.c fac_main.c
src2 = fibo_recur.c fibo_main.c
src3 = fibo_table.c fibo_two.c
src4 = add_integers.c

target1 = factorial_recur
target2 = fibo_recur
target3 = fibo_two
target4 = add_integers

all: $(target1) $(target2) $(target3) $(target4) 
$(target1): $(src1) factorial_recur.h
	gcc -o $(target1) $(src1)
$(target2): $(src2) fibo_recur.h
	gcc -o $(target2) $(src2)
$(target3): $(src3) fibo_table.h
	gcc -o $(target3) $(src3)
$(target4): $(src4)
	gcc -o $(target4) $(src4)

clean:
	rm -rf $(target1) $(target2) $(target3) $(target4) *.txt *.sh *.csv
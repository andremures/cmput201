FLAGS = -Wall -std=c99

main: file_print.o
	gcc $(FLAGS) -o instance_gen assignment3.c *.o

file_print.o: file_print.c
	gcc $(FLAGS) -c file_print.c

clean:
	rm -f instance_gen *.o *.txt

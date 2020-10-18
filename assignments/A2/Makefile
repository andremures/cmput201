FLAGS = -Wall -std=c99

main: sort.o lpt.o johnson.o
	gcc $(FLAGS) -o instance_gen assignment2.c *.o

lpt.o:
	gcc $(FLAGS) -c lpt.c

johnson.o: compare.o
	gcc $(FLAGS) -c johnson.c

sort.o: compare.o
	gcc $(FLAGS) -c sort.c

compare.o:
	gcc $(FLAGS) -c compare.c

clean:
	rm -f *.o

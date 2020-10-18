FLAGS = -Wall -std=c99

main: file_print.o lpt.o johnson.o sort.o compare.o
	gcc $(FLAGS) -o instance_gen assignment3.c *.o

file_print.o: file_print.c
	gcc $(FLAGS) -c file_print.c

lpt.o: lpt.c
	gcc $(FLAGS) -c lpt.c

johnson.o: compare.o johnson.c
	gcc $(FLAGS) -c johnson.c

sort.o: compare.o sort.c
	gcc $(FLAGS) -c sort.c

compare.o: compare.c
	gcc $(FLAGS) -c compare.c

clean:
	rm -f instance_gen *.o

tar:
	tar -cvf assignment3.tar README.txt result.txt instances/.placeholder Makefile average_m_n.pdf average_m.pdf average_n.pdf assignment3.c compare.c compare.h file_print.c file_print.h instance_gen johnson.c johnson.h lpt.c lpt.h sort.c sort.h structs.h

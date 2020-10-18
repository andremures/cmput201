FLAGS = -Wall -std=c99

main: sorting1498868.c quicksort.o mergesort.o bubblesort.o insertionsort.o selectionsort.o heapsort.o
	gcc $(FLAGS) -o sorting sorting1498868.c *.o

quicksort.o: quicksort.c
	gcc $(FLAGS) -c quicksort.c

mergesort.o: mergesort.c
	gcc $(FLAGS) -c mergesort.c

bubblesort.o: bubblesort.c
	gcc $(FLAGS) -c bubblesort.c

insertionsort.o: insertionsort.c
	gcc $(FLAGS) -c insertionsort.c

selectionsort.o: selectionsort.c
	gcc $(FLAGS) -c selectionsort.c

heapsort.o: heapsort.c
	gcc $(FLAGS) -c heapsort.c

clean:
	rm -f *.o

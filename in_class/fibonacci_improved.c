/* This program prints the first 100 numbers of the Fibonacci sequence */

#include <stdio.h> /* The library cntains the 'printf()' */

int main() (
	
	int last = 1, current = 1, next; /* 'main()' is the entrance point for a C program */

	printf("%d ", last);
	printf("%d ", current);
	
	for (int i = 0; i < 98; i++) {
		next = last + current;
		printf("%d ", next);
		last = current;
		current = next;
	}

	return 0;
}

/* Program to demo two kinds of violation accessing memory units
 * 1. You may read the content, but no over-write
   2. You may not even read the content

   Note that you can always check the house address :-)

   Guohui Lin
 */

#include <stdio.h>

int main(void) {

	int i = 3, j = 0;
    int a[10];

	a[i] = 5;
	a[10] = 6;
	a[11] = 11;

	printf("a[%d] %p\n", 0, &a[0]); /* all printf statements cause no violation */
	printf("a[%d] %p\n", 9, &a[9]);
	printf("a[%d] %p\n", 10000, &a[10000]);
	a[10000] = 10;  // out of bounds!
	printf("a[%d] %p\n", 11, &a[11]);
	printf("i %d %p\n", i, &i);
	printf("j %d %p\n", j, &j);
	
	return i + j;
}

//creates Segmentation Fault error - core dumped - getting into memory you're not supposed to ge into

/* Test array subscript out of range */

#include <stdio.h>

#define N 20

int main(void) {

	int a[N], i; 
	int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int c[10] = {1, 2, 3, 4, 5, 6, 7 + 8};
    int d[10] = {0};
    int e[] = {1, 2, 3, 4, 5, 6, 7};
    int f[10] = {[2] = 2, [7] = 9, [9] = 7, [2] = 3};

	for (i = 10; i < N; i++) {
		//a[i] = 0;
		printf("a[%d] = %d\n", i, a[i]);
	}

	printf("array a starts at %p, length is %lu\n", a, sizeof(a));
	printf("array a starts at %p\n", &a[0]);
	printf("array b starts at %p, length is %lu\n", b, sizeof(b));
	printf("array c starts at %p, length is %lu\n", c, sizeof(c));
	printf("array d starts at %p, length is %lu\n", d, sizeof(d));
	printf("array e starts at %p, length is %lu\n", e, sizeof(e));
	printf("array f starts at %p, length is %lu\n", f, sizeof(f));
	for (i = 0; i < 10; i++) {
		printf("a[%d] = %d\t", i, a[i]);
		printf("b[%d] = %d\t", i, b[i]);
		printf("c[%d] = %d\t", i, c[i]);
		printf("d[%d] = %d\t", i, d[i]);
		printf("e[%d] = %d, at %p\t", i, e[i], &e[i]);
		printf("f[%d] = %d\n", i, f[i]);
	}

	return 0;
}

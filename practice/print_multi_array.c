#include <stdio.h>

int main() {
	
	int a[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

	for (int i = 0; i < 2; i++) {
		printf("a[i] = %d\n", *a[i]); // need *
	}
	return 0;
}

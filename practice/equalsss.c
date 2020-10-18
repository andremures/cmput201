#include <stdio.h>

int main() {

	int a[5] = {1, 2, 2, 3, 5};
	for (int i = 0; i < 5; i++) {
		if (i == a[i]) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	}

	return 0;
}

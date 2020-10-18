#include <stdio.h>

int main(void) {
	
	printf("++i\n");
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", i);
	}

	printf("i++\n");
	for (int i = 0; i < 3; i++) {
		printf("%d\n", i);
	}
}

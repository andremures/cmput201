#include <stdio.h>

int main(void) {
	
	int a, b;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	if (a > b) {
		printf("a > b\n");
	} else if (b > a) {
		printf("a < b\n");
	} else {
		printf("a = b\n");
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	
	int i, *p;

	printf("i = %d, p = %p", i, p);
	
	printf("&p has address %p\n", &(&p));
	printf("p has address %p\n", &p);
	printf("p is %p\n", p);
	printf("p points to %d\n", *p);

	return 0;
}

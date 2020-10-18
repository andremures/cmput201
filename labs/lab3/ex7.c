#include <stdio.h>

int main(void) {
	
	int min, max, min1, max1, smallest, largest;
	int n1, n2, n3, n4;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	if ((n1 > n2) || (n1 == n2)) {
		min = n2;
		max = n1;
	} else {
		min = n1;
		max = n2;
	}
	
	if ((n3 > n4) || (n3 == n4)) {
		min1 = n4;
		max1 = n3;
	} else {
		min1 = n3;
		max1 = n4;
	}
	
	smallest = (min > min1 ? min1 : min);
	largest = (max > max1 ? max : max1);

	printf("Largest: %d\n", largest);
	printf("Smallest: %d\n", smallest);
	
	return 0;
}

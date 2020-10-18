#include <stdio.h>

int main() {
	int a[5][9] = {{2},
			{10},
			{1000},
			{10000},
			{5}};
	int* p = a[0];
	
	/* if q was pointing to a[0] the it would be of type int** q
	 * since it is an address and it is pointing to an address as well
	 */

	for (int i = 0; i < 5 * 9; i++) {
		printf("a[%d] = %d\n", i, *(p++));
	
	}
	/* a is a memory address pointing to a[0]
	 * a[0] is a memory address pointing to a[0][0]
	 * p is a memory address pointing to a[0][0] (p = a[0] which points to a[0][0])
	 * 
	 * a[1] is pointing to a[1][0]
	 * ...
	 */ 

	return 0;
}

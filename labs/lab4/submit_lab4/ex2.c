/****************************************************/
/* ex2.c                                            */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: This program takes in two integers  */
/* and finds their largest common divisor then      */
/* prints it out.                                   */
/****************************************************/

#include <stdio.h>

int main() { 
	
	int n, m, rem;

	printf("Enter two integers: ");
	scanf("%d %d", &n, &m);

	while (n != 0) {
		rem = m % n;
		m = n;
		n = rem;
	}

	printf("Greatest common divisor: %d\n", m);

	return 0;
}

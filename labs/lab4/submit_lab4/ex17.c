/****************************************************/
/* ex17.c                                           */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: This program asks the user to input */
/* an odd number and then prints out a magic matrix.*/
/****************************************************/

#include <stdio.h>

int main(void) {
	
	int sqr, n;

	printf("Enter the size of magic square: ");
	scanf("%d", &sqr);
	
	int a[sqr][sqr];

	int i = 0; 
	int j = sqr/2;
	int count = 1;
	for (n = 1; n <= (sqr*sqr); n++) {
		
		a[i][j] = n;
		
		if (count == sqr){
			i++;
			count = 1;
		} else {
			//if i == sqr then wrap around, else decrement it
			i = --i % sqr == -1 ? sqr - 1 : i; 
			//if j == sqr then wrap around, else increment it
			j = ++j % sqr == 0 ? 0 : j;
		       	count++;
		}
	}
	for (int k = 0; k < sqr; k++) {
		for (int l = 0; l < sqr; l++) {
			printf("%5d", a[k][l]);
		}
		printf("\n");
	}
	return 0;
}

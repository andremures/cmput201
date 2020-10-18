/*****************************************************/
/* 1_p217.c                                          */
/* Andreea Muresan                                   */
/* SID: 1498868                                      */
/* Description: This program asks the user to input  */
/* an odd number and then prints out a magic matrix  */
/* using functions to create the matrix and print it.*/
/*****************************************************/

#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]){
  int i = 0;
	int j = n/2;
	int count = 1;
	for (int k = 1; k <= (n*n); k++) {

		magic_square[i][j] = k;

		if (count == n){
			i++;
			count = 1;
		} else {
			//if i == sqr then wrap around, else decrement it
			i = --i % n == -1 ? n - 1 : i;
			//if j == sqr then wrap around, else increment it
			j = ++j % n == 0 ? 0 : j;
		       	count++;
		}
	}
}


void print_magic_square(int n, char magic_square[n][n]){
  for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {
			printf("%5d", magic_square[k][l]);
		}
		printf("\n");
	}
}


int main(void) {
	int sqr;

	printf("Enter the size of magic square: ");
	scanf("%d", &sqr);

	char magic_square[sqr][sqr];

  create_magic_square(sqr, magic_square);
  print_magic_square(sqr, magic_square);

	return 0;
}

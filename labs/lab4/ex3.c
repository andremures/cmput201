/****************************************************/
/* ex3.c                                            */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: This program takes in a fraction in */
/* the form n/m and prints it in lowest terms.      */
/****************************************************/

#include <stdio.h>

int main() {
	
        int num, num2, denom, denom2, rem, gcd;
	
        printf("Enter a fraction: ");
        scanf("%d/%d", &num, &denom);
	num2 = num;
	denom2 = denom;

        while (num != 0) {
                rem = denom % num;
                denom = num;
                num = rem;
        }
	gcd = denom;
	num2 = num2/gcd;
	denom2 = denom2/gcd;

        printf("In lowest terms: %d/%d\n", num2, denom2);

        return 0;
}

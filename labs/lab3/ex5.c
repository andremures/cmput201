/******************************/
/* upc.c                      */
/* Andreea Muresan            */
/* SID: 1498868               */
/******************************/

#include <stdio.h>

int main(void) {

        int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, check, check_digit;
        printf("Enter the first 11 digits of a UPC: ");
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);

        first_sum = d + i2 + i4 + j1 + j3 + j5;
        second_sum = i1 + i3 + i5 + j2 + j4;
        total = 3 * first_sum + second_sum;

        check = (total - 1) % 10;
        if (check < 0) {
                printf("Check digit: 0\n");
        } else {
                check_digit = 9 - check;
                printf("Check digit: %d\n", check_digit);
        }
        return 0;
}

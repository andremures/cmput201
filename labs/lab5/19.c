/************************************************/
/* Name: 19.c                                   */
/* Andreea Muresan                              */
/* Converts an integer input by the user        */
/* into binary form.                            */
/************************************************/
#include <stdio.h>

void pb(int n) {
  if (n != 0) {
    pb(n/2);
    putchar('0' + n %2);
  }
}

int main(void) {

  int n;
  printf("Enter n: "); scanf("%d", &n);

  pb(n);
  printf("\n");

  return 0;
  
}

#include <stdio.h>

int main(void) {
  /*
  // char a[] = {1, 2, 3, 4};
  //
  // for (int i = 0; i < 4; i++) printf("a[%d] = %d\n", i, a[i]);
  char a[] = "January 23rd";
  printf("a: %s\n", a);

  // char *b = "March 26th"; // MEMORY LEAK
  printf("b: %s\n", b);

  char c[] = "January 21st";
  b = c;
  // a = c; // doesn't work
  printf("b: %s\n", b);
  */

  char c[10];
  fgets(c, 10, stdin);
  // int len = sizeof(c)/sizeof(c[0]);
  // for (int i = 0; i <= len; i++) {
  //   putchar(c[i]);
  // }
  puts(c);
}

// read in string, revers that string, then print it back out
// maybe find middle and go outwords, switching the chars in the array
// instead of a[5] use a+5

// a)
// char arr[5]
// arr [3];

//b)
// char *ptr = &arr;
// *(ptr + 3)

#include <stdio.h>

int main(void) {
  char arr[100], *ptr, ch;
  ptr = arr;
  int N = 0;

  for (int i = 0;; i++) {
    ch = getchar();
    if (ch == '\n' || i == 99) break;
    *(ptr + i) = ch;
    N++;
  }

  for (int i = N - 1; i >= 0; i--) putchar(*(ptr + i));
  printf("\n");

  return 0;
}

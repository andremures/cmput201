// *(arr+3)

#include <stdio.h>

int main(void) {
  char arr[100];
  char ch;
  int N = 0;

  for (int i = 0;; i++) {
    ch = getchar();
    if (ch == '\n' || i == 99 || ch == '\0') break;
    *(arr + i) = ch;
    N++;
  }

  for (int i = N - 1; i >= 0; i--) putchar(*(arr + i));
  printf("\n");

  return 0;
}

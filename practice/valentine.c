#include <stdio.h>

int valentine(int a[], int n);

int main(void) {

  int a[11] = {1, 6, 4, 8, 9, 5, 6, 4, 8, 1, 9};
  int num = valentine(a, 11);

  printf("the single number is %d\n", num);

  return 0;
}

int valentine(int a[], int n) {
  int num = 0;

  for (int i = 0; i < n; i++) {
    num ^= a[i];
  }

  return num;
}

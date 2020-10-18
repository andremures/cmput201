// ignore inputs that arent letters
// isalpha() from <ctype.h>
// tolower() from <ctype.h>
// strlen() to find length of char array - string
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool odd(char a[], int l, int r);
bool even(char a[], int l, int r);

int main(void) {
  int N = 0; // keep track of length of string
  char a[100], ch;

  for (int i = 0;; i++) {
    ch = getchar();
    int b = isalpha(ch);
    ch = tolower(ch);
    if (ch == '\n' || i == 99) break;
    if (isalpha(ch) != 0) {
      printf("b = %d  ", b);
      a[i] = ch;
      printf("a[%d] = %c\n", i, a[i]);
      N++;
    } else if (ch == ' ') {
      printf("a[%d] is %c\n", i, ch);
    }
  }
  for (int i = 0; i < N; i++) {
    printf("%c ", a[i]);
  }
  printf("\n");

  bool palindrome;
  palindrome = N % 2 == 0 ? even(a, 0, N-1) : odd(a, 0, N-1);

  if (palindrome) printf("palindrome\n");
  else printf("not a palindrome\n");

  return 0;
}

bool odd(char a[], int l, int r) {
  if (l == r) return true;
  if (a[l] == a[r]) return odd(a, l+1, r-1);
  else return false;
}

bool even(char a[], int l, int r) {
  if (r < l) return true;
  if (a[l] == a[r]) return even( a, l+1, r-1);
  else return false;
}

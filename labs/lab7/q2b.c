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
  char ch, a[100], *ptr;
  ptr = &a[0];


  for (int i = 0;; i++) {
    ch = getchar();
    ch = tolower(ch);
    if (ch == '\n' || i == 99) break;
    if (isalpha(ch)) {
      *(ptr + i) = ch;
      N++;
    }
  }

  bool palindrome;
  palindrome = N % 2 == 0 ? even(ptr, 0, N-1) : odd(ptr, 0, N-1);

  if (palindrome) printf("palindrome\n");
  else printf("not a palindrome\n");

  return 0;
}

bool odd(char *ptr, int l, int r) {
  if (l == r) return true;
  if (*(ptr + l) == *(ptr + r)) {
    return odd(ptr, l+1, r-1);
  } else {
    return false;
  }
}

bool even(char *ptr, int l, int r) {
  if (r < l) return true;
  if (*(ptr + l) == *(ptr + r)) return even(ptr, l+1, r-1);
  else return false;
}

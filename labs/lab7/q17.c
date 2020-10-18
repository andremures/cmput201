// ignore inputs that arent letters
// isalpha() from <ctype.h>
// tolower() from <ctype.h>
// strlen() to find length of char array - string
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool odd(char a[], int l, int r);
bool even(char a[], int l, int r);
bool is_palindrome(const char *message);

int main(void) {
  int N = 0;
  char ch, a[100], *message;
  message = a;
  memset(message, 0, sizeof(char)*100);

  for (int i=0;; i++) {
    ch = getchar();
    ch = tolower(ch);
    if (ch == '\n' || i == 99) break;
    if (isalpha(ch)) {
      *(message + N) = ch;
      N++;
    }
  }

  if (is_palindrome(message)) printf("palindrome\n");
  else printf("not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message) {
  const char *left;
  const char *right;

  left = right = message;
  while (*right != '\0') {
    right++;
  }
  right--;

  while (left < right) {
    if (*left != *right) {
      return false;
    }
    left++;
    right--;
  }

  return true;
}

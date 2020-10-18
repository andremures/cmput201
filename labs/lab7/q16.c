#include <stdio.h>
#include <string.h>

void reverse(char *message);

int main(void) {
  int N = 0;
  char a[100], ch, *message;
  message = a;
  memset(message, 0, sizeof(char)*100);

  for (int i = 0;; i++) {
    ch = getchar();
    if (ch == '\n' || i == 99) break;
    a[i] = ch;
    N++;
  }

  reverse(message);

  puts(message);

  return 0;
}

void reverse(char *message) {
  char *left;
  char *right;

  left = right = message;
  while (*right != '\0') {
    right++;
  }
  right--;

  while (left < right) {
    char temp = *left;
    *left = *right;
    *right = temp;
    left++;
    right--;
  }

}

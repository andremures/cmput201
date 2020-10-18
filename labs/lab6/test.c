#include <stdio.h>

struct cell{
  int num;
  int maybe[9];
};

int main(void) {
  // printf("\n");
  // int a[3][3][3];
  // int n = 0;
  // for (int i = 0; i < 3; i++){
  //   for (int j = 0; j < 3; j++){
  //     for (int k = 0; k < 3; k++) {
  //       a[i][j][k] = n++;
  //       printf("%d ", a[i][j][k]);
  //     }
  //     printf(" ");
  //     n=0;
  //   }
  //   printf("\n");
  // }

  // int i = 5;
  // printf("%d\n", (i++) % 2);
  // printf("%d\n", (i) % 2);
  // return 0;

  struct cell puzzle[9][9];

  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     for (int k = 0; k <= 10; k++) {
  //       puzzle[i][j].maybe[k] = 0;
  //     }
  //   }
  // }

  puzzle[0][0].num = 0;
  printf("one\n");
  printf("num = %d\n", puzzle[0][0].num);
  printf("two\n");
  printf("maybe[0] = %d\n", puzzle[0][0].maybe[0]);
  // printf("three\n");

  while (getchar() != '\n');

}

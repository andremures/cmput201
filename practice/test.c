#include <stdio.h>
int main(void) {

  int a[5] = {1, 2, 3, 4, 5};

  printf("sizeof(a): %lu\n", sizeof(a));
  for (int i=0;i< sizeof(a)/sizeof(a[0]);i++)
    printf("%d\n", a[i]);
  // int i=5, j=6;
  // float x=7, y=8;
  //
  // printf("Enter values for i, x, j, y: ");
  // printf("scanf() reads in %d values: ", scanf("%d %f %d %f", &i, &x, &j, &y));
  // printf("i=%d, x=%f,j=%d,y=%f\n",i,x,j,y);

  return 0;
}

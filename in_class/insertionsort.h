#include "insertionsort.h"
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void insertionsort(int a[], int left, int right);

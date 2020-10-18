
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
}
int split(int a[], int left, int right, int *pivot) {
  *pivot = left;
  int compare = 0;

  while (1) {
    while (a[left] <= a[right]) {
      compare++;
      right--;
    }

    if (*pivot == left) {
      compare++;
      break;
    }

    else if (a[*pivot] > a[right]) {
      compare++;
      int temp = a[right];
      a[right] = a[*pivot];
      a[*pivot] = temp;
      *pivot = right;
    }
  }

  return compare;
 }

 int quicksort (int a[], int left, int right) {
   int pivot;
   int compare1 = 0;
   int compare2 = 0;
   int compare = 0;
   if (left < right) {
     split(a, left, right, &pivot);
     compare1 = quicksort(a, left, pivot - 1);
     compare2 = quicksort(a, pivot + 1, right);
   }
   compare = compare1 + compare2;
   return compare;
 }

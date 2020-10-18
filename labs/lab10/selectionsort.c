#include "selectionsort.h"

int selection_sort(int a[], int size) {

  int compare = 0;

  for (int first = 0; first < size; first++) {
    for (int second = first + 1; second < size; second++) {
      compare++;
      if (a[first] >= a[second]) {
        int temp = a[first];
        a[first] = a[second];
        a[second] = temp;
      }
    }
  }
  return compare;
}

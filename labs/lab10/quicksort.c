#include "quicksort.h"

 int split(int a[], int left, int right, int* compare);

 int quicksort(int a[], int left, int right) {
   int compare = 0;

 	if (left >= right) {
 		return 0;
 	}
  
 	int mid = split(a, left, right, &compare);

 	return quicksort(a, left, mid - 1) + quicksort(a, mid + 1, right) + compare;
 }

 int split(int a[], int left, int right, int* cmp) {
    int compare = 0;
 	int pivot = a[left];

 	while (left < right) {
 	    while (left < right && a[right] >= pivot) {
            compare++;
 			right--;
 		}
 		a[left] = a[right];
 		while (left < right && a[left] < pivot) {
            compare++;
 			left++;
 		}
 		a[right--] = a[left];
 	}
 	a[left] = pivot;
   *cmp = compare;
 	return left;
 }

#include "mergesort.h"

int merge_sort(int a[], int left, int right) {
  int compare = 0;

	if (left >= right) {
		return compare;
  }

	int mid = (left + right) / 2;
	compare = merge_sort(a, left, mid) + merge_sort(a, mid + 1, right);

	for (int i = left; i <= mid; i++){
		for (int j = mid + 1; j <= right; j++) {
      compare++;
			if (a[i] > a[j]) {
				int temp = a[j];
				for (int k = j; k > i; k--)
					a[k] = a[k-1];
				a[i] = temp;
				mid++;
			}
    }
  }
	return compare;
}

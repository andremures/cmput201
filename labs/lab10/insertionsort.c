#include "insertionsort.h"

int insertion_sort(int a[], int length) {
  int compare = 0;

	for (int i = 1; i < length; i++) {
		for (int j = 0; j < i; j++) {
      compare++;
			if (a[i] < a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	return compare;
}

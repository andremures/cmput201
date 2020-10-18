#include "bubblesort.h"

int bubble_sort(int a[], int length) {
	int compare = 0;

	for (int i = 0; i < length - 1; i++) {
		compare++;
		if (a[i] > a[i+1]) {
			int tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
			bubble_sort(a, length);
		}
	}

	return compare;
}

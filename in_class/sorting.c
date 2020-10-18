/* This program demos bubble sort, insertion sort, and quicksort in separate functions:
 *
 * Guohui Lin
 */

#include <stdio.h>

void quicksort(int a[], int left, int right);
int split(int a[], int left, int right);
void bubblesort(int a[], int length);
void insertionsort(int *, int);
void mergesort(int a[], int left, int right);

int main(void) {
	int length;

	printf("Enter the length of the array: ");
	if (scanf("%d", &length) != 1 || length < 2) {
		printf("No sorting executed due to empty or singleton array!\n");
		return -1;
	}
	int a[length], b[length];

	printf("Enter %d integers to be sorted: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	bubblesort(a, length);

	printf("In bubble sorted non-decreasing order: ");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	insertionsort(b, length);

	printf("In insertion sorted non-decreasing order: ");
	for (int i = 0; i < length; i++)
		printf("%d ", b[i]);
	printf("\n");

	mergesort(a, 0, length-1);

	printf("In merge sorted non-decreasing order: ");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void insertionsort(int a[], int length) {
	for (int i = 1; i < length; i++) { // count the number of comparisons made?
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) { // swap a[i], a[j]
				int tmp = a[i];

				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	return;
}

void bubblesort(int a[], int length) {
	for (int i = 0; i < length - 1; i++) { // count the number of comparisons made?
		if (a[i] > a[i+1]) { // swap a[i], a[i+1], re-set i
			int tmp = a[i];

			a[i] = a[i+1];
			a[i+1] = tmp;
			i = -1;
		}
	}

	return;
}

void quicksort(int a[], int left, int right) {

	if (right <= left) {
		return;
	}

	int mid = split(a, left, right);

	quicksort(a, left, mid - 1);
	quicksort(a, mid + 1, right);

	return;
}

int split(int a[], int left, int right) {
	int pivot = a[left];

	while (left < right) {
		while (left < right && a[right] >= pivot){
			right--;
		}
		a[left] = a[right];
		while (left < right &&& a[left] < pivot) {
			left++;
		}
		a[right--] = a[left];
	}
	a[left] = pivot;
	return left;
}

void mergesort(int a[], int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid+1, right);

	int i = left, j = mid + 1, k = 0;
	int length = right - left + 1;
	int b[length];
	for (; k < length; k++) {
		if (a[i] <= a[j]){
			b[k] = a[i++];
			if (i > mid) break;
		} else {
			b[k] = a[j++];
			if (j > right) break;
		}
	}
	for (; j <= right; j++)
		b[++k] = a[j];
	for (; i <= mid; i++)
		b[++k] = a[i];
	for (k = 0; k < length; k++)
		a[left + k] = b[k];

	return;
}

void mergesort2(int a[], int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid+1, right);

	for (int i = left; i <= mid; i++) {
		for (int j = mid+1; j <= right; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return;
}

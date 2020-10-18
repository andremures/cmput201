/* This program demos bubble sort and insertion sort, all in main function:
 *
 * Add quicksort, and pull all sorting algorithms out out main()
 *
 * Guohui Lin
 */

#include <stdio.h>

void mergesort(int a[], int left, int right);
void quicksort(int a[], int left, int right);
int split(int a[], int left, int right);
void bubblesort(int a[], int length);
void insertionsort(int *, int);

int main(void) {
	int length;

	printf("Enter the length of the array: ");
	if (scanf("%d", &length) != 1 || length < 2) {
		printf("No sorting executed due to empty or singleton array!\n");
		return -1;
	}
	int a[length], b[length];

	printf("\nEnter %d integers to be sorted: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	printf("\nThe entered %d integers in original order:\t", length);
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	mergesort(a, 0, length-1);

	printf("\nIn merge sorted non-decreasing order:\t\t");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	quicksort(a, 0, length-1);

	printf("\nIn quick sorted non-decreasing order:\t\t");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	bubblesort(a, length);

	printf("\nIn bubble sorted non-decreasing order:\t\t");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");

	insertionsort(b, length);

	printf("\nIn insertion sorted non-decreasing order:\t");
	for (int i = 0; i < length; i++)
		printf("%d ", b[i]);
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
			bubblesort(a, length);// re-write bubblesort as a recursion
		}
	}

	return;
}

void quicksort(int a[], int left, int right) {

	if (left >= right) {// termination condition: at most 1 element in the array
		return;
	}

	int mid = split(a, left, right);

	quicksort(a, left, mid - 1);
	quicksort(a, mid + 1, right);
	return;
}

int split(int a[], int left, int right) {
	int pivot = a[left];

	while (left != right) {
		while (left != right && a[right] >= pivot) {
			right--;
		}
		a[left++] = a[right];
		while (left != right && a[left] < pivot) {
			left++;
		}
		a[right--] = a[left];
	}
	a[left] = pivot;
	return left;
}

void mergesort(int a[], int left, int right) {

	if (left >= right) {// termination condition: at most 1 element in the array
		return;
	}

	int mid = (left + right) / 2;

	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	// need to insert here how to merge the two sorted subarrays a[left .. mid] and a[mid + 1 .. right]

	return;
}

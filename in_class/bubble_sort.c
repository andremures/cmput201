// This program demos bubble sort and insertion sort, all in main function:

#include <stdio.h>

void bubblesort(int a[], int);

int main(void) {

	int length;

	printf("length = %d\n", length);
	printf("Enter the length of the array: ");
	if (scanf("%d", &length) != 1 || length < 2) {
		printf("No sorting executed due to empty or singleton array!\n");
		return -1;
	}
	int a[length], b[length];

	printf("length = %d size of a is %lu\n", length, sizeof(a));
	printf("Enter %d integers to be sorted: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	
	bubblesort(a, length);

	for (int i = 1; i < length; i++) { // count the number of comparisons made?
		for (int j = 0; j < i; j++) {
			if (b[i] < b[j]) { // swap b[i], b[j]
				int tmp = b[i];

				b[i] = b[j];
				b[j] = tmp;
			}
		}
	}

//	printf("length = %d size of a is %lu\n", length, sizeof(a));
	printf("In Insertion sorted non-decreasing order: ");
	for (int i = 0; i < length; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}

void bubblesort(int a[], int length) {
	for (int i = 0; i < length - 1; i++) { 
		if (a[i] > a[i+1]) { 
			int tmp = a[i];

			a[i] = a[i+1];
			a[i+1] = tmp;
			i = -1;
		}
	}

	printf("In sorted non-decreasing order: ");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
}

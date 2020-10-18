/****************************************************/
/* sorting1498868.c                                 */
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: Takes in the size of an array of    */
/* numbers to be sorted and sorts them based on the */
/* desired sorting algorithm and outputs number of  */
/* comparisons as well as the sorted array.         */
/****************************************************/

#include "sorting1498868.h"

int split(int a[], int left, int right);

int main(int argc, char** argv) {
	int length;

	printf("Enter the number of integers to be sorted: ");
	if (scanf("%d", &length) != 1 || length < 2) {
		printf("Array length too short!\n");
		return -1;
	}

	int a[length], b[length];

	printf("Enter %d integers to be sorted: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	printf("The input order for the %d integers is: ", length);
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");


  // PRINT COMPARISONS AND ORDER

  if (strcmp(argv[1], "-q") == 0)  {
	  int compare = quicksort(a, 0, length-1);
	  printf("Quicksort performs in total %d comparisons\n", compare);
  }
	else if (strcmp(argv[1], "-m") == 0)  {
	  int compare = merge_sort(a, 0, length-1);
	  printf("Mergesort performs in total %d comparisons\n", compare);
  }
	else if (strcmp(argv[1], "-i") == 0)  {
		int compare = insertion_sort(a, length);
		printf("Insertion sort performs in total %d comparisons\n", compare);
	}
	else if (strcmp(argv[1], "-b") == 0)  {
		int compare = bubble_sort(a, length);
		printf("Bubble sort performs in total %d comparisons\n", compare);
	}
	else if (strcmp(argv[1], "-s") == 0)  {
		int compare = selection_sort(a, length);
		printf("Selection sort performs in total %d comparisons\n", compare);
		printf("The sorted order is \"");
	}
	else if (strcmp(argv[1], "-h") == 0)  {
		int compare = heap_sort(a, length);
		printf("Heap sort performs in total %d comparisons\n", compare);
	}
	else {
		printf("Invalid input\n");
		return 1;
	}

	printf("The sorted order is \"");
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\b\".\n");

	return 0;
}

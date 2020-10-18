#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void) {
  int a = [1, 2, 3, 4];
  int b = [5, 6, 7, 8];
  findMedianSortedArrays(a, sizeof(a), b, sizeof(b));

  return 1;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;

    int *totalArray = (int*) malloc(sizeof(int) * totalSize);

    for (int i = 0; i < nums1Size; i++) {
      totalArray[i] = *nums1;
      nums1++;
    }

    for (int j = 0; j < nums1Size; j++) {
      printf("%d \n", totalArray[j]);
    }

    return 1;
}

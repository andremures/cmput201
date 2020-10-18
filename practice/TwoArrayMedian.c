#include <stdio.h>

void findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void) {

  int odd1[] = 

  int *a1;
  int array1[] = {1, 2, 3, 4, 5};
  a1 = array1;

  int *a2;
  int array2[] = {6, 7, 8};
  a2 = array2;

  int *a1;
  int array3 = {1, 2, 3, 4};
  a1 = array3;

  int *a2;
  int array4 = {5, 6, 7, 8};
  a2 = array4;



  findMedianSortedArrays(a1, 5, a2, 3);

  return 1;
}

void findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int centre1, centre2;

    // odd case
    if (nums1Size % 2 != 0) {
        centre1 = *(nums1 + (nums1Size/2));
        printf("%d\n", centre1);
    }

    return;
}

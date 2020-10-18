#include "heapsort.h"

int heapify(int a[], int size) {
  int compare = 0;
  int i = 0;

  while (i < size) {
    int node = a[i];
    int left_child_i = i * 2 + 1; //assign left child index
    int right_child_i = i * 2 + 2; // assign right child index

    int smallest;

    if (left_child_i < size && right_child_i < size) {
      smallest = a[left_child_i] <= a[right_child_i] ? left_child_i : right_child_i;
      compare++;
    } else if (left_child_i < size) {
      smallest = left_child_i;
    } else if (right_child_i < size) {
      smallest = right_child_i;
    } else {
      break;
    }

    compare++;
    if (node > a[smallest]) {
      a[i] = a[smallest];
      a[smallest] = node;
      i = smallest;
      continue;
    }

    break;
  }
  return compare;
}

int heap_sort(int a[], int size) {
  int compare = 0;

  for (int i = 0; i < size; i++) {
    int leaf = i;
    while (leaf > 0) {
      int parent = (leaf - 1) / 2;
      compare++;
      if (a[leaf] < a[parent]) {
        int temp = a[parent];
        a[parent] = a[leaf];
        a[leaf] = temp;
      }
      leaf = parent;
    }
  }

  for (int i = 0; i < size - 1; i++) {

    compare += heapify(&a[i], size - i);

  }

  return compare;

}

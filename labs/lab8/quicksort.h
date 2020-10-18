/************************************************/
/* Header file used in quicksort.c and qsort.c  */
/************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#define N 10

#include <stdio.h>

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

#endif

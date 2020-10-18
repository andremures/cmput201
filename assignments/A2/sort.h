// compare and sort jobs
#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include "structs.h"
#include "compare.h"

void quicksort(struct Job a[], int (*compare)(struct Job*, struct Job*), int left, int right);
void johnson_sort(struct Job jobs[], int left, int right);

int compare_lpt(struct Job* j1, struct Job* j2);

#endif

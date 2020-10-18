#include "sort.h"

// compares processing times for lpt
int compare_lpt(struct Job* j1, struct Job* j2) {
  return j2->processing_time[0] - j1->processing_time[0];
}

int split(struct Job a[], int (*compare)(struct Job*, struct Job*), int left, int right) {
	struct Job pivot = a[left];

	while (left < right) {
		while (left < right && compare(&a[right], &pivot) >= 0) {
			right--;
		}
		a[left] = a[right];
		while (left < right && compare(&a[left], &pivot) < 0) {
			left++;
		}
		a[right--] = a[left];
	}
	a[left] = pivot;
	return left;
}

// quicksorts array of type struct Job
void quicksort(struct Job a[], int (*compare)(struct Job*, struct Job*), int left, int right) {
	if (right <= left) {
		return;
	}

	int mid = split(a, compare, left, right);

	quicksort(a, compare, left, mid - 1);
	quicksort(a, compare, mid + 1, right);

	return;
}

/*******************************************************************************/

void swap(struct Job* j1, struct Job* j2) {
  struct Job temp = *j1;
  *j1 = *j2;
  *j2 = temp;
}

void johnson_sort(struct Job jobs[], int left, int right) {
  // only sorts part of the list of jobs, from given left to right
  while (left < right) {
    int min_index = left;
    int min_time = jobs[left].processing_time[1];
    struct Job min_job = jobs[left];
    for (int i = left; i <= right; i++) {
      if (jobs[i].processing_time[1] < min_time || jobs[i].processing_time[2] < min_time) {
        min_job = jobs[i];
        min_time = min(jobs[i].processing_time[1], jobs[i].processing_time[2]);
        min_index = i;
      }
    }

    bool is_B = min_job.processing_time[1] == min_time;
    if (is_B) {
      swap(&jobs[min_index], &jobs[left]);
      left++;
    } else {
      swap(&jobs[min_index], &jobs[right]);
      right--;
    }
  }
}

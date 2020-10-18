// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "compare.h"
#include "structs.h"
#include "lpt.h"
#include "johnson.h"
#include "sort.h"

/*******************************************************************************/

int main(void) {
  int n = 0, m = 0;
  struct Job *jobs = 0;
  int p1, p2, p3;

  // user input
  printf("Enter the number of machines in stage 1: ");
  if (scanf("%d", &m) != 1) {
    printf("Error in reading number of machines!\n");
  }

  printf("Enter the number of jobs: ");
  if (scanf("%d", &n) != 1) {
    printf("Error in reading number of jobs!\n");
  }

  jobs = calloc(n, sizeof(struct Job));

  printf("Enter in each line the processing times for a job: ");

  // populate jobs with data
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &p1, &p2, &p3);
    jobs[i].id = i + 1;
    jobs[i].processing_time[0] = p1;
    jobs[i].processing_time[1] = p2;
    jobs[i].processing_time[2] = p3;
  }

  // call lpt and johnson functions
  int T = 0; // the time now
  int lpt_time = 0, johnson_time = 0;

  quicksort(jobs, compare_lpt, 0, n - 1);
  lpt_time = lpt(jobs, 0, min(m, n), m, 0);

  if (m < n) {
    johnson_sort(jobs, m, n - 1);
    johnson_time = johnson(jobs, m, n, 0);
  }

  T = max(lpt_time, johnson_time);

  if (m < n) {
    quicksort(jobs, compare_lpt, m, n - 1);
    lpt_time = lpt(jobs, m, n, m, T);
  }

  johnson_sort(jobs, 0, min(m, n) - 1);
  johnson_time = johnson(jobs, 0, min(m, n), T);

  T = max(lpt_time, johnson_time);
  printf("\nThe LPT-Johnson schedule has an overall makespan %d.\n", T);

  free(jobs);
	return 0;
}

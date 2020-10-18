/************************************/
/* Student ID: 1498868              */
/* Collab Students:                 */
/* Other Collabs:                   */
/* Resources:                       */
/************************************/

// main file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "structs.h"
#include "file_print.h"

#define K 100
#define MAX_N 200
#define MAX_M 20
#define START_T 1
#define MAX_T2 100

/*******************************************************************************/

int main(void) {
  int num_jobs;
  struct Job *jobs;
  // int p1, p2, p3;

  // user input
  // printf("Enter the number of machines in stage 1: ");
  // if (scanf("%d", &machines) != 1) {
  //   printf("Error in reading number of machines!\n");
  // }

  // printf("Enter the number of jobs: ");
  // if (scanf("%d", &num_jobs) != 1) {
  //   printf("Error in reading number of jobs!\n");
  // }


  // printf("Enter in each line the processing times for a job: ");

  // // populate jobs with data
  // for (size_t i = 0; i < num_jobs; i++) {
  //   scanf("%d %d %d", &p1, &p2, &p3);
  //   jobs[i].id = (short) (i + 1);
  //   jobs[i].processing_time[0] = p1;
  //   jobs[i].processing_time[1] = p2;
  //   jobs[i].processing_time[2] = p3;
  // }

  srand(time(NULL));

  // printf("\n");

  num_jobs = K * MAX_M * (MAX_N / 10) * (MAX_T2 / 10);

  for (int i = 1; i <= K; i++) {
    for (int m = 1; m <= MAX_M; m++) {
      for (int n = 10; n <= MAX_N; n+=10) {
        for (int t_2 = 10; t_2 <= MAX_T2; t_2+=10) {
          jobs = (struct Job*) malloc(n * sizeof(struct Job));
          for (int j = 0; j < n; j++) {
            jobs[j].id = (short) j;
            jobs[j].processing_time[0] = rand() % (t_2 + 1 - START_T);
            jobs[j].processing_time[1] = rand() % (t_2 + 1 - START_T);
            jobs[j].processing_time[2] = rand() % (t_2 + 1 - START_T);
          }
          fprint_instance(m, n, START_T, t_2, i, jobs);
          free(jobs);
        }
      }
    }
  }


  // // call lpt and johnson functions
  // int T = 0; // the time now
  // int lpt_time = 0, johnson_time = 0;
  //
  // quicksort(jobs, compare_lpt, 0, num_jobs - 1);
  // lpt_time = lpt(jobs, 0, min(machines, num_jobs), machines, 0);
  //
  // if (machines < num_jobs) {
  //   johnson_sort(jobs, machines, num_jobs - 1);
  //   johnson_time = johnson(jobs, machines, num_jobs, 0);
  // }
  //
  // T = max(lpt_time, johnson_time);
  //
  // if (machines < num_jobs) {
  //   quicksort(jobs, compare_lpt, machines, num_jobs - 1);
  //   lpt_time = lpt(jobs, machines, num_jobs, machines, T);
  // }
  //
  // johnson_sort(jobs, 0, min(machines, num_jobs) - 1);
  // johnson_time = johnson(jobs, 0, min(machines, num_jobs), T);
  //
  // T = max(lpt_time, johnson_time);
  // printf("\nThe LPT-Johnson schedule has an overall makespan %d.\n", T);

	return 0;
}

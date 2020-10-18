#include "johnson.h"

int johnson(struct Job* jobs, int left, int right, int t) {
  // find starting times for jobs on machine B
  int b_time = t;
  for (int j = left; j < right; j++) {
    jobs[j].start_time[1] = b_time;
    b_time = jobs[j].start_time[1] + jobs[j].processing_time[1];
  }

  // find starting times for jobs on machine C
  jobs[left].start_time[2] = jobs[left].start_time[1] + jobs[left].processing_time[1];
  int c_time = jobs[left].start_time[2] + jobs[left].processing_time[2];
  for (int j = left + 1; j < right; j++) {
    jobs[j].start_time[2] = max(c_time, jobs[j].start_time[1] + jobs[j].processing_time[1]);
    c_time = jobs[j].start_time[2] + jobs[j].processing_time[2];
  }

  int T = c_time;

  // print out information
//  printf("\nJohnson's order: ");
//  for (int i = left; i < right - 1; i++) {
//    printf("%d, ", jobs[i].id);
//  }
//  printf("%d\n\n", jobs[right-1].id);
//
//  printf("Job information:\n");
//  for (int i = left; i < right; i++) {
//    printf("job %d is processed on B starting %d, on C starting %d;\n", jobs[i].id, jobs[i].start_time[1], jobs[i].start_time[2]);
//  }
//
//  printf("\nMachine information:\nB processes ");
//  for (int i = left; i < right-1; i++) {
//    printf("job %d at %d, ", jobs[i].id, jobs[i].start_time[1]);
//  }
//  printf("job %d at %d;\n", jobs[right-1].id, jobs[right-1].start_time[1]);
//
//  printf("C processes ");
//  for (int i = left; i < right-1; i++) {
//    printf("job %d at %d, ", jobs[i].id, jobs[i].start_time[2]);
//  }
//  printf("job %d at %d;\n", jobs[right-1].id, jobs[right-1].start_time[2]);
//
//
//  printf("The job processing time interval is [%d, %d], and the makespan is %d\n", t, T, T - t);

  return T;
}

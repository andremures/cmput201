#include "lpt.h"

int lpt(struct Job* jobs, int left, int right, int m, int t) {
  int T = t;
  int l = left;
  struct Machine *machines = calloc(m, sizeof(struct Machine));

  // set initial free_time and numjobs, allocate memory for machine job
  for (int i = 0; i < m; i++) {
    machines[i].free_time = t;
    machines[i].jobs = calloc((right - left), sizeof(struct Job));
    machines[i].numjobs = 0;
  }

  // assign jobs to machines
  while (l < right) {
    for (int i = 0; i < m; i++) {
      if (machines[i].free_time <= T) {
        jobs[l].start_time[0] = T;
        jobs[l].machineA = i + 1;
        machines[i].jobs[machines[i].numjobs] = jobs[l];
        machines[i].free_time = T + jobs[l].processing_time[0];
        machines[i].numjobs++;
        l++;
        break;
      }
    }

    // find minimum free_time among machines
    int minimum = INT_MAX;
    for (int i = 0; i < m; i++) {
      if (machines[i].free_time < minimum) {
        minimum = machines[i].free_time;
      }
    }
    T = minimum;
  }

  // find maximum free_time among machines
  int maximum = INT_MIN;
  for (int i = 0; i < m; i++) {
    if (machines[i].free_time > maximum) {
      maximum = machines[i].free_time;
    }
  }
  T = maximum;

 // print out information
  printf("\nLPT order: ");
  for (int i = left; i < right - 1; i++) {
    printf("%d, ", jobs[i].id);
  }
  printf("%d\n\n", jobs[right-1].id);

  printf("Job Information:\n");
  for (int i = left; i < right; i++) {
    printf("job %d is processed on A_%d starting %d;\n", jobs[i].id, jobs[i].machineA, jobs[i].start_time[0]);
  }

  printf("\nMachine information:\n");
  for (int i = 0; i < m; i++) {
    printf("A_%d processes ", i+1);

    if (machines[i].numjobs == 0) {
      printf(".\n");
      continue;
    }

    for (int j = 0; j < machines[i].numjobs - 1; j++) {
      printf("job %d at %d, ", machines[i].jobs[j].id, machines[i].jobs[j].start_time[0]);
    }
    printf("job %d at %d;\n", machines[i].jobs[machines[i].numjobs-1].id, machines[i].jobs[machines[i].numjobs-1].start_time[0]);
  }

  printf("The job processing time interval is [%d, %d], and the makespan is %d\n", t, T, T - t);

  for (int i = 0; i < m; i++) {
    free(machines[i].jobs);
  }
  free(machines);

  return T;
}

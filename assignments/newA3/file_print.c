#include "file_print.h"

void fprint_instance(int m, int n, int t_1, int t_2, int i, struct Job *jobs) {
  char filename[50], filepath[50];
  sprintf(filename, "instance%d_%d_%d_%d_%d.txt", m, n, t_1, t_2, i);
  sprintf(filepath, "instances/%s", filename);

  FILE* out;
  if (!(out = fopen(filepath, "w"))) {
   printf("Could not open file %s : %s\n", filepath, strerror(errno));
   exit(errno);
  }

  fprintf(out, "%s\n", filename);
  fprintf(out, "# number of machines in stage 1:\n%d\n", m);
  fprintf(out, "# number of jobs:\n%d\n", n);
  fprintf(out, "# job processing times:\n");

  for (int j = 0; j < n; j++) {
    fprintf(out, "%d %d %d\n", jobs[j].processing_time[0], jobs[j].processing_time[1], jobs[j].processing_time[2]);
  }

  fprintf(out, "\n# end of instance\n");
  fflush(out);
  fclose(out);
}

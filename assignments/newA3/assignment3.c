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
#include "sort.h"
#include "compare.h"
#include "johnson.h"
#include "lpt.h"

#define K 100
#define MAX_N 200
#define MAX_M 20
#define START_T 1
#define MAX_T2 100

/*******************************************************************************/

int makespan(struct Job *jobs, int num_jobs, int machines);
float ratio(struct Job *jobs, int n, int m);

int main(int argc, char** argv) {

    if (argc != 2 || (strcmp(argv[1], "-r") != 0)) {

        printf(">instance_gen -r\n");

        return 1;

    } else if ((strcmp(argv[1], "-r") == 0)) {

        clock_t t;
        t = clock();

        char filename[50];
        sprintf(filename, "result.txt");

        FILE *results;
        if (!(results = fopen(filename, "w"))) {
            printf("Could not open file %s : %s\n", filename, strerror(errno));
            exit(errno);
        }

        struct Job *jobs;

        srand(time(NULL));

        float RMN[MAX_M][MAX_N / 10];
        float RM[MAX_M];
        float RN[MAX_N / 10];
        float R = 0.0;

        memset(RN, 0, MAX_N / 10);

        for (int m = 1; m <= MAX_M; m++) {

            float rm = 0;

            for (int n = 10; n <= MAX_N; n += 10) {

                float rmn = 0;

                for (int t_2 = 10; t_2 <= MAX_T2; t_2 += 10) {
                    for (int i = 1; i <= K; i++) {
                        jobs = (struct Job *) malloc(n * sizeof(struct Job));
                        for (int j = 0; j < n; j++) {
                            jobs[j].id = (short) j;
                            jobs[j].processing_time[0] = rand() % (t_2 + 1 - START_T);
                            jobs[j].processing_time[1] = rand() % (t_2 + 1 - START_T);
                            jobs[j].processing_time[2] = rand() % (t_2 + 1 - START_T);
                        }

                        fprint_instance(m, n, START_T, t_2, i, jobs);

                        float r = ratio(jobs, n, m);
                        rmn += r;
                        rm += r;
                        RN[n / 10 - 1] += r;
                        R += r;

                        free(jobs);
                    }
                }

                RMN[m - 1][n / 10 - 1] = rmn / (MAX_T2 / 10 * K);

            }

            RM[m - 1] = rm / (MAX_N / 10 * MAX_T2 / 10 * K);

        }

        for (int j = 0; j < MAX_N / 10; j++) {
            RN[j] /= MAX_M * MAX_T2 / 10 * K;
        }

        R /= MAX_M * MAX_N / 10 * MAX_T2 / 10 * K;

        for (int m = 0; m < MAX_M; m++) {
            for (int n = 0; n < MAX_N / 10; n++) {
                fprintf(results, "%f ", RMN[m][n]);
            }
            fprintf(results, "\n");
        }
        fprintf(results, "\n");

        for (int m = 0; m < MAX_M; m++) {
            fprintf(results, "%f ", RM[m]);
        }
        fprintf(results, "\n\n");

        for (int n = 0; n < MAX_N / 10; n++) {
            fprintf(results, "%f ", RN[n]);
        }
        fprintf(results, "\n\n");

        fprintf(results, "%f", R);

        t = clock() - t;
        double time_taken = ((double) t) / CLOCKS_PER_SEC;

        fprintf(results, "\n\n%f", time_taken);

        fflush(results);
        fclose(results);
    }

    return 0;
}

float ratio(struct Job *jobs, int n, int m) {
    int S = makespan(jobs, n, m);

    quicksort(jobs, compare_lpt, 0, n - 1);

    float l_1 = 0;
    for (int iter = 1; iter < n; iter++) {
        l_1 += jobs[iter].processing_time[0];
    }

    l_1 = max(jobs[0].processing_time[0], l_1 / m);

    float l_2 = johnson(jobs, 0, n - 1, 0);

    float L = max(l_1, l_2);

    float r = S / L;

    return r;
}

int makespan(struct Job *jobs, int num_jobs, int machines) {

    // call lpt and johnson functions
    int T = 0; // the time now
    int lpt_time = 0, johnson_time = 0;

    quicksort(jobs, compare_lpt, 0, num_jobs - 1);
    lpt_time = lpt(jobs, 0, min(machines, num_jobs), machines, 0);

    if (machines < num_jobs) {
        johnson_sort(jobs, machines, num_jobs - 1);
        johnson_time = johnson(jobs, machines, num_jobs, 0);
    }

    T = max(lpt_time, johnson_time);

    if (machines < num_jobs) {
        quicksort(jobs, compare_lpt, machines, num_jobs - 1);
        lpt_time = lpt(jobs, machines, num_jobs, machines, T);
    }

    johnson_sort(jobs, 0, min(machines, num_jobs) - 1);
    johnson_time = johnson(jobs, 0, min(machines, num_jobs), T);

    T = max(lpt_time, johnson_time);

    return T;
}

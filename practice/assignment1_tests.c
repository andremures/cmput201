/*************************************************/
/* Assignment 1 test program                     */
/*************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {

        int machines, jobs;
        if (argc != 2 || (strcmp(argv[1], "-i") != 0 && (strcmp(argv[1], "-r") != 0))) {

                printf(">instance_gen -i | -r\n");

                return 1;

        } else if ((strcmp(argv[1], "-i") == 0)){

                // USER INPUT
                printf("Enter the number of machines in the in stage 1: ");
                if (scanf("%d", &machines) != 1) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }
                printf("Enter the number of jobs: ");
                if (scanf("%d", &jobs) != 1) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }

                printf("Enter in each line the processing times for a job: ");

                int ptimes[jobs][3];
                for (int i = 0; i < jobs; i++) {
                        if (scanf("%d %d %d", &ptimes[i][0], &ptimes[i][1], &ptimes[i][2]) != 3) {
                                printf("Error in reading the instance!\n");
                                return -1;
                        }
                }

		// PRINT OUT
                printf("\n#instance%d_%d_1.txt\n", machines, jobs);
                printf("#number of machines in stage 1:\n%d\n", machines);
                printf("#number of jobs:\n%d\n", jobs);
                printf("#job processing times:\n");

                for (int i = 0; i < jobs; i++) {
                        printf("%d %d %d\n", ptimes[i][0], ptimes[i][1], ptimes[i][2]);
                }
                printf("#end of instance\n\n");


        } else if ((strcmp(argv[1], "-r") == 0)) {

                //USER INPUT
                int t_1, t_2, instances;

                printf("Generating random instances ...\n");
                printf("Enter the number of machines in stage 1: ");
                if (scanf("%d", &machines) != 1) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }
                printf("Enter the number of jobs: ");
                if (scanf("%d", &jobs) != 1) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }
                printf("Enter the time processing interval [t_1, t_2]: ");
                if (scanf("%d %d", &t_1, &t_2) != 2) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }
                printf("Enter the number of instances to be generate: ");
                if (scanf("%d", &instances) != 1) {
                        printf("Error in reading the instance!\n");
                        return -1;
                }

                // PRINT OUT
                int ptimes[jobs][3];

                srand(time(NULL));

                printf("\n\n");
                for (int i = 1; i < (instances + 1); i++) {
                       printf("#instance%d_%d_%d.txt\n", machines, jobs, i);
                       printf("#number of machines in stage 1:\n%d\n", machines);
                       printf("#number of jobs:\n%d\n", jobs);
                       printf("#job processing times:\n");

                       for (int j = 0; j < jobs; j++) {
                               for (int k = 0; k < 3; k++) {
                                       ptimes[j][k] = t_1 + (rand() % (t_2 - t_1));
                               }
                               printf("%d %d %d\n", ptimes[j][0], ptimes[j][1], ptimes[j][2]);
                       }
                       printf("#end of instance\n\n\n");
                }
        }
        return 0;
}

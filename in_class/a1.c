/*************************************************/
/* a1.c                                          */
// student ID: 1498868
// collaborative students: ...
// other collaborations: ...
// other resources: ...

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
   
   int num_machines, num_jobs;
   int job[num_jobs][3];

   /* 1st spec */
   if (argc != 2) {
      
      return -1; // not zero so we can check where it terminates later
   } 

   if (strcmp(argv[1], "-i") == 0) {
      printf("Enter number of machines: ");
      if (scanf("%d", &num_machines) != 1) {
         
         
         return -2;
      }
      
      printf("#the number of machines in stage 1: \n %d\n", num_machines);
      return 10;
   }
   if (strcmp(argv[1], "-r") == 0) {
   }
   
   return 0;
}

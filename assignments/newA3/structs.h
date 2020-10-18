#ifndef STRUCTS_H
#define STRUCTS_H

struct Job {
  short id;
  int processing_time[3];       //the three processing times
  int machineA;                 //the stage-1 machine selected
  int start_time[3];            //the start time on the three machines
};

struct Machine {
  int free_time;
  int numjobs;
  struct Job* jobs;
};

#endif

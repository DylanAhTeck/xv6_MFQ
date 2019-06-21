#include "param.h"
#define NPSTAT 64
#define NTICKS 500

struct pstat
{
    int pid;      // PID of each process
    char *name;   // name of the process
    int priority; // current priority level of each process (0-2)
    int ticks[3]; // number of ticks each process used the last time it was
    // scheduled in each priority queue
    // cannot be greater than the time-slice for each queue

    int times[3]; // number of times each process was scheduled at each of 3
    // priority queues
    int queue[NTICKS]; //queue that a RUNNABLE process is sitting in during each tick

    int total_ticks; // total number of ticks each RUNNABLE process has
    // accumulated in all queues
    // this value should be equal to the sum of the 3 values in ticks

    int wait_time; // number of ticks each RUNNABLE process waited in the lowest
    // priority queue
};

struct pstat pstat_var[NPSTAT];
/*
pid -> DONE. Take from proc stucture
name -> DONE. 
priority -> DONE. Update in addToQueue.
ticks -> DONE. Done after timeslice completed in scheduler
times -> DONE. Done after timeslice completed in scheduler
queue -> DONE. Done during each completed tick in updatePstat()
total_ticks -> Done during each completed tick in updatePstat()
wait_time -> Done during each completed tick in updatePstat()


*/
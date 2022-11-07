#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct pstat {
    int inuse[NPROC];  // whether this slot of the process table is in use (1 or 0)
    int pid[NPROC];    // PID of each process
    char name[16][NPROC]; // name of each process
    int priority[NPROC];  // current priority level of each process (0-7)
    enum procstate state[NPROC]; // current state (e.g., SLEEPING or RUNNABLE) of each process
    int ticks[NPROC][NPRIO];  // number of ticks each process has accumulated at each of the 8 priority levels
};

#endif // _PSTAT_H_
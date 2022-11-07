// clang-format off
#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
// clang-format on

int main(int argc, char *argv[]) {
    struct pstat proc = {0};
    if(getpinfo(&proc) < 0) {
        printf(1, "getpinfo failed\n");
        return -1;
    }
    printf(1, "PID\tPriority\tName\tState\tTicks: (q0\tq1\tq2\tq3\tq4\tq5\tq6\tq7)\n");
    for(int i = 0; i < NPROC; i++) {
        if(proc.inuse[i]) {
            printf(1, "%d\t%d\t\t%s\t%d\t       (%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d)\n", proc.pid[i], proc.priority[i], proc.name[i], proc.state[i], proc.ticks[i][0], proc.ticks[i][1], proc.ticks[i][2], proc.ticks[i][3], proc.ticks[i][4], proc.ticks[i][5], proc.ticks[i][6], proc.ticks[i][7]);
        }
    }
    exit();
}
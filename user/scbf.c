// clang-format off
#include "types.h"
#include "stat.h"
#include "user.h"
// clang-format on

int main(int argc, char *argv[]) {
    int rc;
    printf(1, "Parent PID: %d\n", getpid());
    for (int i = 1; i <= 5; i++) {
        rc = fork();
        if (rc == 0) {
            // Child
            printf(1, "Child %d PID: %d\n", i, getpid());
            for (;;) {
            }
        }
    }
    exit();
}
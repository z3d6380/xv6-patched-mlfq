// clang-format off
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
// clang-format on

int main(int argc, char *argv[]) {
  int rc;
  printf(1, "Parent PID: %d\n", getpid());
  for (int i = 1; i <= 1; i++) {
    rc = fork();
    if (rc == 0) {
      // child
      printf(1, "Child %d PID: %d\n", i, getpid());
      for (;;) {
          sleep(1000);
          // int fd = open("thrash", O_RDWR);
          // write(fd, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 512);
          // close(fd);
      }
    }
  }
  exit();
}
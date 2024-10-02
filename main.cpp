

#include <pthread.h>
#include <sys/wait.h>

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main() {

  int pid;

  for (int i = 0; i < 3; i++) {
    pid = fork(); // fork system call returns 0

    if (pid == 0) // child process
    {
      cout << " i am child process " << i + 1 << endl;
      sleep(1); // sleep so that child processes can print before grandhcild
                // processes start printing
      for (int j = 0; j < i + 1; j++) {
        pid = fork();
        if (pid == 0) // grandchild process
        {
          cout << " i am a grandchild process from child process " << i + 1
               << endl;

          _exit(0); // if you dont exit the grandchild process can call fork()
                    // again
        }
      }
      for (int j = 0; j < i + 1; j++) {
        wait(nullptr); // need to wait for child processes to finish
      }
      sleep(5); // not necessary only used for demonstration to check child
                // processes in terminal
      _exit(0);
    }
  }

  // only parent is running ( parent will wait for each child thread 3 in this
  // case )

  for (int i = 0; i < 3; i++) {
    wait(nullptr);
  }
  cout << " i am the parent process " << endl;

  return 0;
}
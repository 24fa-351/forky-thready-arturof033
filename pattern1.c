#include "pattern1.h"

void forkProcess1(int numberOfProcesses){

    printf("----Starting Process 1: ----\n");

    for(int ix = 0; ix < numberOfProcesses; ix++) {

        pid_t pid;
        pid = fork();

        if(pid != 0) {

            int status;
            pid_t child_pid = waitpid(pid, &status, 0);

            if (child_pid == -1) {
                perror("waitpid");
                exit(1);
            }

            printf("Parent process (PID: %d) waited for child (PID: %d)\n", getpid(), child_pid);
            parentProcess1(ix);
            
        }
        else if (pid == 0) {

            childProcess1(ix);
            exit(1);

        }
        else { 

            perror("Fork failed");
            exit(1);

        }
    }
}

void parentProcess1(int processIndex){

    printf("Process %d starting\n", processIndex);
    printf("Parent created child for %d (pid %d)\n", processIndex, getpid());

    sleepProcess1();

}

void childProcess1(int processIndex){

    printf("Child %d starting\n", processIndex);
    printf("Child process %d exiting.\n", processIndex);

}

void sleepProcess1(){

    srand(time(NULL));
    int random_num = rand() % (8 - 1 + 1) + 1;

    printf("Will sleep for %d second(s).\n", random_num);
    sleep(random_num);
    
}
#include "pattern2.h"

void forkProcess2(int numberOfProcesses){

    printf("----Starting Process 2: ----\n");
        
    forkRepeater(0, numberOfProcesses);

}

void parentProcess2(int processIndex) {

    printf("Process %d starting\n", processIndex);
    printf("Parent created child for %d (pid %d)\n", processIndex, getpid());

    sleepProcess2();
    
}

void childProcess2(int processIndex, int numberOfProcesses){

    printf("Child %d starting\n", processIndex);
    printf("Child process %d exiting.\n", processIndex);

    forkRepeater(processIndex + 1, numberOfProcesses);

}

void forkRepeater(int processIndex, int numberOfProcesses){

    if(processIndex < numberOfProcesses)
    {

        pid_t pid = fork();

        if(pid != 0){

            int status;
            pid_t child_pid = waitpid(pid, &status, 0);

            if (child_pid == -1) {
                perror("waitpid");
                exit(1);
            }

            printf("Parent process (PID: %d) waited for child (PID: %d)\n", getpid(), child_pid);
            parentProcess2(processIndex);

        }
        else {

            childProcess2(processIndex, numberOfProcesses);
            exit(1);
        }
    }
}

void sleepProcess2(){

    srand(time(NULL));
    int random_num = rand() % (8 - 1 + 1) + 1;

    printf("Will sleep for %d second(s).\n", random_num);
    sleep(random_num);

}
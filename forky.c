#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "pattern1.h"
#include "pattern2.h"

/*
    ./forky <pattern number> <number of processes>

    pattern number: 1,2,3
    number of processes: 1+

    Will create a series of subprocesses in the pattern specified. 
*/

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s [123] <num>\n", argv[0]);
        return 1;
    }
    if (argv[1][0] != '1' && argv[1][0] != '2') {
        printf("Invalid pattern number.\nEnter 1 or 2.\n");
        return 1;
    }
    int patternNum = argv[1][0] - '0';

    int numberOfProcesses;
    if (0 == sscanf(argv[2], "%d", &numberOfProcesses)
        || numberOfProcesses < 1 || numberOfProcesses > 256) {
        printf("Invalid number of processes.\nInput must be  1 < n < 256.\n");
        return 1;
    }

    if(patternNum == 1) {
        forkProcess1(numberOfProcesses);
    }
    else if(patternNum == 2) {
        forkProcess2(numberOfProcesses);
    }

    return 0;
}
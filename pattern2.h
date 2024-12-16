#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#ifndef PATTERN2_H
#define PATTERN2_H

void forkProcess2(int numberOfProcesses);

void parentProcess2(int processIndex);

void childProcess2(int processIndex, int numberOfProcesses);

void forkRepeater(int processIndex, int numberOfProcesses);

void sleepProcess2();

#endif
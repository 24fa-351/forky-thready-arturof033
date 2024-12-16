#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#ifndef PATTERN1_H
#define PATTERN1_H

void forkProcess1(int numberOfProcesses);

void parentProcess1(int numberOfProcesses);

void childProcess1(int processToCreate);

void sleepProcess1();

#endif
#pragma once
#include <stddef.h>
#include "queue.h"

#define MININT -2147483648

// cache parameters
int numSet;
int associativity;
int blockSize;
char filePath[100];
int verbose = 0;
int policy;// 0 for LRU, 1 for 2Q

// final results
int hit = 0, miss = 0, eviction = 0;

// will be set in getopt() function
extern char *optarg;

// you can define functions here
void usage();
void parseline(int argc, char **argv);

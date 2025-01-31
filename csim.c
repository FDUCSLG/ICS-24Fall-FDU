#include "cachelab.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csim.h"
#include <getopt.h>
#include <limits.h>
#include <math.h>

void usage()
{
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file> -q <policy>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("  -q <policy>  Replacement policy (LRU or 2Q)\n");
    printf("\n");
    printf("Examples:\n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace -q LRU\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace -q 2Q\n");
    exit(1);
}

// parse command line and get the parameters
void parseline(int argc, char **argv)
{
    int opt;
    int num = 0;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:q:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            usage();
            break;
        case 'v':
            verbose = 1;
            break;
        case 's':
            num = atoi(optarg);
            if (num == 0 && optarg[0] != '0')
            {
                printf("./csim: Missing required command line argument\n");
                usage();
            }
            numSet = num;
            break;
        case 'E':
            num = atoi(optarg);
            if (num == 0 && optarg[0] != '0')
            {
                printf("./csim: Missing required command line argument\n");
                usage();
            }
            associativity = num;
            break;
        case 'b':
            num = atoi(optarg);
            if (num == 0 && optarg[0] != '0')
            {
                printf("./csim: Missing required command line argument\n");
                usage();
            }
            blockSize = num;
            break;
        case 't':
            strcpy(filePath, optarg);
            break;
        case 'q':
            if (strcmp(optarg, "LRU") == 0 || strcmp(optarg, "2Q") == 0)
            {
                if (strcmp(optarg, "LRU") == 0)
                    policy = 0;
                else
                    policy = 1;
            }
            else
            {
                fprintf(stderr, "Invalid replacement policy: %s\n", optarg);
                exit(1);
            }
            break;
        case ':':
            printf("./csim: Missing required command line argument\n");
            usage();
            break;
        case '?':
            usage();
            break;
        default:
            printf("getopt error");
            exit(1);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    parseline(argc, argv);
    // create_cache();
    // Simulate();
    // free_cache();
    printSummary(hit, miss, eviction);
    return 0;
}
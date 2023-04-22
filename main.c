/*
Authors: Matthew Sparr and Zac Palmer
Class: CSCI 340
Professor Leclerc 
Assignment: Final Project

I certify that this is soley the work of Matthew Sparr and Zac Palmer
-----------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "project.h"

int main(int argc, char *argv[])
{

    printf("\nThis might take a little time to run. Please just wait it works. (maybe)\n\n");
    int cache_size;
    double cacheRefTime;

    int max = MAX_BLOCK_SIZE;
    cache_size = get_cache_block_size(max);
    main_ref_time(cache_size);
    printf("Finished thank you for your time.\n");

    printf("block size = %d\n", max);
    // -------
    return 0;
}
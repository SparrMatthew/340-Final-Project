#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "project.h"

double cacheRefTime;

int get_cache_block_size(int maximum)
{
    int block_size;
    long start;
    int lenChange = (16 * MB) - 1;
    double avgTime, currTime;
    int time = 0;
    int l1, l2, l3;
    int lvl_jump = 0;
    double temp_time_1, temp_time_2 = 0;
    static int array[16 * MB];
    int i, j;
    unsigned int k;
    int count = 0;
    double cacheRefTime;

    int cacheSize;

    // outermost loop
    for (i = 1; i <= maximum; i *= 2)
    {
        temp_time_1 = avgTime;
        avgTime = 0;
        // int cache_jump;
        // printf("DEBUG: temptime1: %lf\n", temp_time_1);

        for (j = 0; j < 6; j++)
        {
            start = clock();

            // timing array, this is why it takes forever
            for (k = 0; k < 512 * MB; k++)
            {
                time += array[(k * i) & lenChange];
            }

            currTime = (double)(clock() - start) / CLOCKS_PER_SEC;
            avgTime += currTime;
        }

        avgTime /= 6;
        temp_time_2 = avgTime;
        // printf("DEBUG: For i value: %d    Time Taken:%lf\n",i,avgTime)

        if (count == 5)
        {
            block_size = i;
        }

        if (lvl_jump == 1)
        {
            l1 = i;
            cacheRefTime = avgTime;
        }
        if (lvl_jump == 2)
        {
            l2 = i;
            cacheSize = l2;
        }
        if (lvl_jump == 3)
        {
            l3 = i;
        }

        if (temp_time_1 > 0 && temp_time_1 != temp_time_2 && temp_time_2 >= temp_time_1)
        {
            double diff = temp_time_2 - temp_time_1;

            // any time the current cache time is greater than 30% of the previous time that indicates a jump in cache level
            if (diff > (temp_time_1 * 0.30))
            {
                lvl_jump++;

                // cache_jump = i;
                // printf("DEBUG: cache jump at byte size: %d\n", cache_jump);
            }
        }
        printf("Still working please wait: %d\n", count);
        count++;
    }
    printf("Number of loops: %d\n", count);
    printf("DEBUG: time variable - %d\n\n", time);
    printf("\nCache Block Size: %d bytes\n", block_size);
    printf("L1 Cache Size: %d\n", l1 << 2);
    printf("L2 Cache Size: %d\n", l2 << 2);

    // unknown reason why l3 is not working and it isnt finding 
    if (l3 == 3)
    {
        cacheSize = l3;
        printf("L3 Cache Size: %d\n", l3 << 2);
    }
    else
    {
        printf("L3 Cache Size: unconfirmed\n");
    }

    cache_ref_time(cacheRefTime);

    return cacheSize;
}

void main_ref_time(int cacheSize)
{
    int x[cacheSize + 1];
    int start = clock();
    x[0] = 1;
    double currTime = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Main Memory Access Time: %lf seconds\n", currTime);
}

void cache_ref_time(double time)
{

    printf("\nAverage Reference Time for Cache: %f ns\n", time);
}

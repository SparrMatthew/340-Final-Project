CSCI 340 Operating Systems Final Project
Professor Leclerc

Matthew Sparr and Zac Palmer

Questions to be anwserd:
1. How big is a cache block?
    By altering the array iteration step within the get_cache_block_size function, one can measure the impact on 
    computation time. The cache line size in bytes can be determined by identifying the step ('i' value) where 
    a significant change in time taken occurs.

2. How big is the cache?
    The function get_cache_block_size can be used to determine the cache size through its adjunct cache levels.

3. How long does a reference to main memory take to complete?
    Once the L3 cache size has been determined, the main_ref_time function creates an array slightly larger
    than the L3 cache and measures the time taken for a single reference.

4. How long does a reference that can be satisfied from cache take to complete?
    The access times obtained from the get_cache_block_size function will be utilized to calculate the duration 
    taken for a cache reference to be executed.


Problems when working on this project:
   Upon investigation, we determined that a substantial increase in the average time taken to access cache between successive 
   sizes implied a transition to a higher cache level. However, we faced uncertainty regarding the precise time difference 
   required to signify such a shift. Ultimately, we concluded that an increase of 25% or more in time would serve as an indicator 
   of a jump to a new cache level.

    The run time for our project is exceptionally long and our biggest projblem. We suspect that this is due to the comparison loop being executed with 
    an array that grows exponentially in size. 

    Different CPU's: With one of us using an i7 Intel chip and the other using an M1 chip we ran into some data issues. 
    Had a lot of diffrent times with the two. Saw a couple that were almost double that of the others. 

    Warnings with unused variable 'cacheRefTime' we ued this in project.c but for some reason we are getting this Warning
    
    Used a lot of debugging throughout this project and probelms that we dont understand.



Compiling and Running: 

    in terminal: make
                ./main

When the file is ran this is where it takes longer than Expected
It will run and compile completly just takes a while. So do not exit.

Expected output:
This might take a little time to run. Please just wait it works.
Below will change from computer to computer this is my personal output:

Still working please wait: count num
"   "   "   "   "   "   "
"   "   "   "   "   "   "
"   "   "   "   "   "   "
"   "   "   "   "   "   "
"   "   "   "   "   "   "
"   "   "   "   "   "   "
"   "   "   "   "   "   "
DEBUG: I left this on due to making sure out time variable was still 0

Cache Block Size: 32 bytes
L1 Cache Size: 64
L2 Cache Size: 128
L3 Cache Size: 512

Average Reference Time for Cache: 1.717108 ns
Main Memory Access Time: 0.000001 seconds



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "sys/time.h"

#define TRIALS 8
#define EXPERIMENTS 4
#define MATRIX_SIZE 2048

short A[MATRIX_SIZE][MATRIX_SIZE],
      B[MATRIX_SIZE][MATRIX_SIZE],
      C[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

int main(int argc, char*  argv[])
{
	// Initalize array A and B with '1's
	for (int i = 0; i < MATRIX_SIZE; ++i)
		for (int k = 0; k < MATRIX_SIZE; ++k)
			A[i][k] = B[i][k] = 1;

	// Run TRIALS number of trials for each block size
	for (int trial = 0; trial < TRIALS; ++trial)
	{
		long long average = 0;
		long long fastest = LLONG_MAX;

		printf("Trial %d: ", trial);

		// Iterate through the block sizes
		for (int block_size = 4; block_size <= (2 << EXPERIMENTS); block_size *= 2)
		{
			// Keep track of when we start doing work
			struct timeval time_start;
			gettimeofday(&time_start, NULL);


			// Do work..


			// Keep track of when we finish our work
			struct timeval time_end;
			gettimeofday(&time_end, NULL);

			// Keep track of the time for averaging later
			long long execution_time = 1000000LL
				* (time_end.tv_sec  - time_start.tv_sec)
				+ (time_end.tv_usec - time_start.tv_usec);

			fastest  = fastest < execution_time ? fastest : execution_time;
			average += execution_time;

			printf("%lld,", execution_time);
			fflush(stdout);
		}

		printf("%lld,%lld\n", average / TRIALS, fastest);
	}

	return 0;
}

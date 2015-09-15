#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Test program run time */
int main(int argc, char **argv)
{
	struct timespec tBeginTime, tEndTime;
	unsigned int N;
	int i, j, k, count = 0;

	if (argc != 2) {
	   fprintf(stderr, "Usage: %s <nloops>\n", argv[0]);
	   exit(1);
	}

	N = atoi(argv[1]);

	clock_gettime(CLOCK_MONOTONIC, &tBeginTime);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				count++;

	clock_gettime(CLOCK_MONOTONIC, &tEndTime);
	double fCostTime = (tEndTime.tv_sec - tBeginTime.tv_sec) + 
					   (double)(tEndTime.tv_nsec - tBeginTime.tv_nsec)/1000000000;

	printf("[clock_gettime]Program Cost Time = %.10f Sec\n", fCostTime);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Num.h"

/* output all of prime numbers that are less than max_num */
int
main(int argc, char **argv)
{
	int i, j, max_num;
	struct timespec tBeginTime, tEndTime;

	if (argc != 2) {
	   fprintf(stderr, "Usage: %s <max_num>\n", argv[0]);
	   exit(1);
	}

	max_num = atoi(argv[1]);

	Type *prime_num = malloc(max_num * sizeof(Type));
	if (prime_num == NULL) {
	   fprintf(stderr, "Insufficient memory.\n");
	   exit(1);
	} 
	
	clock_gettime(CLOCK_MONOTONIC, &tBeginTime);

	for (i = 2; i < max_num; i++)
		prime_num[i] = 1;

	for (i = 2; i < max_num; i++) {
		if (prime_num[i]) {
			for (j = i; j <= max_num/i; j++)
				prime_num[i*j] = 0;
		}
	}

/*	for (i = 2; i < max_num; i++) {
		if (prime_num[i])
			printf("%4d ", i);
	}

	putchar('\n'); */
	
	clock_gettime(CLOCK_MONOTONIC, &tEndTime);
	double fCostTime = (tEndTime.tv_sec - tBeginTime.tv_sec) + 
		(double)(tEndTime.tv_nsec - tBeginTime.tv_nsec)/1000000000;

	printf("[clock_gettime]Program Cost Time = %.10f Sec\n", fCostTime);

	return 0;
}

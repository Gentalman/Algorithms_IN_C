#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	int j, r, nloops;
	unsigned int seed;
	unsigned int max_num;

	if (argc != 4) {
	   fprintf(stderr, "Usage: %s <seed> <max_num> <nloops>\n", argv[0]);
	   exit(1);
	}

	seed = atoi(argv[1]);
	max_num = atoi(argv[2]);
	nloops = atoi(argv[3]);

	srand(seed);
	for (j = 0; j < nloops; j++) {
	   r =  rand() % (max_num + 1);
	   printf("%d ", r);
	}
	putchar('\n');

	return 0;
}


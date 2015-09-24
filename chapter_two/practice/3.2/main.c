#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef	int Number;

Number rand_num(void)
{
	return rand();
}

int
main(int argc, char *argv[])
{
	int i, nloops;
	unsigned int max_num;
	Number x;
	float m1 = 0.0, m2 = 0.0;

	if (argc != 3) {
	   fprintf(stderr, "Usage: %s <max_num> <nloops>\n", argv[0]);
	   exit(1);
	}

	max_num = atoi(argv[1]);
	nloops = atoi(argv[2]);

	for (i = 0; i < nloops; i++) {
		x =  rand_num() % max_num;
		m1 += ((float)x) / nloops;
		m2 += ((float)x*x) / nloops;
	}

	printf("      Average: %lf\n", m1);
	printf("Std.deviation: %lf\n", sqrt(m2 - m1*m1));

	return 0;
}


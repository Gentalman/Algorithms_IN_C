#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Num.h"

/* output all of prime numbers that are less than max_num */
int
main(int argc, char **argv)
{
	int i, j, k, max_num;

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
	
	int *prime_num_times = malloc(max_num * sizeof(int));
	if (prime_num_times == NULL) {
	   fprintf(stderr, "Insufficient memory.\n");
	   exit(1);
	}

	for (k = 2; k <= max_num; k++) {
		for (i = 2; i <= k; i++)
			prime_num[i] = 1;

		for (i = 2; i <= k; i++) {
			if (prime_num[i]) {
				for (j = i; j <= max_num/i; j++)
					prime_num[i*j] = 0;
			}
		}

		for (i = 2; i <= k; i++) {
			if (prime_num[i])
				prime_num_times[k]++;
		}
	}

	for (i = 2; i <= max_num; i++) {
		printf("%2d", i);

		for (j = 0; j < prime_num_times[i]; j+=5)
			printf("*");

		printf("\n");
	}

	printf("\n");

	return 0;
}

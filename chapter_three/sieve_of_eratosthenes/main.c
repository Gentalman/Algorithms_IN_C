#include <stdio.h>
#include <stdlib.h>

/* output all of prime numbers that are less than max_num */
int
main(int argc, char **argv)
{
	int i, j, max_num;

	if (argc != 2) {
	   fprintf(stderr, "Usage: %s <max_num>\n", argv[0]);
	   exit(1);
	}

	max_num = atoi(argv[1]);

	int *prime_num = malloc(max_num * sizeof(int));
	if (prime_num == NULL) {
	   fprintf(stderr, "Insufficient memory.\n");
	   exit(1);
	} 
		

	for (i = 2; i < max_num; i++)
		prime_num[i] = 1;

	for (i = 2; i < max_num; i++) {
		if (prime_num[i]) {
			for (j = i; j <= max_num/i; j++)
				prime_num[i*j] = 0;
		}
	}

	for (i = 2; i < max_num; i++) {
		if (prime_num[i])
			printf("%4d ", i);
	}

	putchar('\n');

	return 0;
}

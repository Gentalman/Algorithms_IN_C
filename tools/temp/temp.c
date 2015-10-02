#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	int max_num;

	if (argc != 2) {
	   fprintf(stderr, "Usage: %s <max_num> \n", argv[0]);
	   exit(1);
	}

	max_num = atoi(argv[1]);

	int *p = malloc(max_num * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}

	return 0;
}

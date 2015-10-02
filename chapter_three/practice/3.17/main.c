#include <stdio.h>
#include <stdlib.h>

#define	MAX_NUM 1000

int
main(int argc, char **argv)
{
/*	if (argc != 4) {
	   fprintf(stderr, "Usage: %s <seed> <max_num> <nloops>\n", argv[0]);
	   exit(1);
	}*/

	int i, num;

	int *freq = malloc(MAX_NUM * sizeof(int));	//numbers' frequence than less than MAX_NUM
	if (freq == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}

	for (i = 0; i < MAX_NUM; i++)
		freq[i] = 0;
	
	while (scanf("%d", &num) == 1) {
		if (num < MAX_NUM)
			freq[num]++;
	}

	for (i = 0; i < MAX_NUM; i++) {
		printf("%2d %2d\n", i, freq[i]);
	}
	
	return 0;
}

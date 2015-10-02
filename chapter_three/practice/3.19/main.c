#include <stdio.h>
#include <stdlib.h>

#define	MAX_NUM 1000

int
main(int argc, char **argv)
{
	int i, j, num;
	int cnt = 0;
	int times = 0;

	int *freq = malloc(MAX_NUM * sizeof(int));	//number' frequence than less than MAX_NUM
	if (freq == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}

	for (i = 0; i < MAX_NUM; i++)
		freq[i] = 0;
	
	while (1) {
		num = rand() % MAX_NUM;
		cnt++;
		freq[num]++;
		
		for (j = 0; j < MAX_NUM; j++) {
			if (freq[j] > 1)
				times++;
		}
		if (times == MAX_NUM)
			break;
		else
			times = 0;
	}

	printf("generate %d num\n", cnt);

	return 0;			
}

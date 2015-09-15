#include <stdio.h>

//define OUTPUT_MESSAGE
#define	N 10000

/* use c language to achieve the tree-high quick-union algorithms */
int main(int argc, char **argv)
{
	int buf, i, j;
	int p, q, data[N], th[N];	//th array represent height of the tree
	int access_data_array_times = 0;

	for (i = 0; i < N; i++)	{
		data[i] = i;
		th[i] = 1;
	}

	while (scanf("%d %d", &p, &q) == 2) {
		if (p >= N || q >= N) {
			printf("input error: data can not be greater than %d\n", N); 
			printf("please try again\n");

			continue;
		}
		
		//find the root of the tree
		for (i = p; i != data[i]; i = data[i]) 
			access_data_array_times++;
		for (j = q; j != data[j]; j = data[j]) 
			access_data_array_times++;

		if (i == j)	{
#ifdef	OUTPUT_MESSAGE
			printf("%d and %d is connect!\n", p , q);
#endif
		}
		else if (th[i] == th[j]) {	//judge which trees highter
			data[j] = i;
			th[i]++;
		}
		else if (th[i] < th[j]) { 
			data[i] = j;
		}
		else {
			data[j] = i;
		}
		access_data_array_times++;

		/*
		for (i = 0; i < N; i++)
			printf("%d ", data[i]);
		printf("\n");
		*/

#ifdef	OUTPUT_MESSAGE
		printf("access the data array times is %d\n", access_data_array_times);
#endif
	}

	return 0;
}

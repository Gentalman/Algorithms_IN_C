#include <stdio.h>

//define OUTPUT_MESSAGE
#define	N 10000

/* use c language to achieve the weighted quick-union algorithms */
int main(int argc, char **argv)
{
	int buf, i, j;
	int p, q, data[N], sz[N];	//sz array represent weighted of the tree
	int access_data_array_times = 0;

	for (i = 0; i < N; i++)	{
		data[i] = i;
		sz[i] = 1;
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
		else if (sz[i] < sz[j]) { 
			data[i] = j;
			sz[j] += sz[i];
		}
		else {
			data[j] = i;
			sz[i] += sz[j];
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

#include <stdio.h>
#include <stdlib.h>

/* create a 3d matrix */
int ***malloc3d(int l, int w, int h)
{
	int i, j;

	int ***t = malloc(l * sizeof(int **));

	for (i = 0; i < l; i++) {
		t[i] = malloc(w * sizeof(int *));
	}

	for (i = 0; i < l; i++) {
		for (j = 0; j < w; j++) {
			t[i][j] = malloc(h * sizeof(int));
		}
	}

	return t;
}

int
main(int argc, char **argv)
{
	int i, j ,k;
	int num = 0;

	int ***matrix = malloc3d(2, 2, 2); 

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				matrix[i][j][k] = num;
				num++;
			}
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				printf("point[%d][%d][%d] is %d\n", i, j, k, matrix[i][j][k]);
			}
		}
	}

	return 0;
}

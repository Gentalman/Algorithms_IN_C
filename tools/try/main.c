#include <stdio.h>

#define N 100000

main()
{ 
/*	unsigned int i, j, a[N];
    for (i = 2; i < N; i++) a[i] = 1;
    for (i = 2; i < N; i++)
      if (a[i])
        for (j = i; j*i < N; j++) a[i*j] = 0;
    for (i = 2; i < N; i++)
      if (a[i]) printf("%4d ", i);
    printf("\n");*/

	printf("%d %d", sizeof(char), sizeof(int));
}

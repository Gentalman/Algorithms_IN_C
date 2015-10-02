#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 1000

int
main(int argc, char **argv)
{
	int c;
	int len = 1000;
	int index = 0;
	char *str = malloc(len * sizeof(char));
	if (str == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}

	while ((c = getchar()) != EOF) {
		if (isspace(c))
			continue;
		else if (isalpha(c)) {
			str[index++] = c;
			if (index == len) {
				len *= 2;
				str = realloc(str, len);
			}
		}
		else {
			fprintf(stderr, "input data only include alphabet\n");
			exit(1);
		}
	}
	str[index] = '\0';

	int i;
	int max = strlen(str);

	for (i = 0; i <= max/2; i++) {
		if (str[i] != str[max-1-i]) {
			printf("The string isn't palindrome\n");
			return 0;
		}
	}

	printf("The string is palindrome\n");

	return 0;
}

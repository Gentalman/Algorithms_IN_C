#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node* next;
} Node, *list_node;

int
main(int argc, char **argv)
{
	int i;
	int sum;	//represent total people
	int pos;
	list_node delete_node, temp;

	if (argc != 3) {
	   fprintf(stderr, "Usage: <sum> <pos>\n", argv[1], argv[2]);
	   exit(1);
	}

	sum = atoi(argv[1]);
	pos = atoi(argv[2]);

	list_node head = malloc(sizeof(Node));
	if (head == NULL) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}
	head->item = 1, head->next = head;

	list_node current_node = head;

	for (i = 2; i <= sum; i++) {
		current_node->next = malloc(sizeof(Node));
		if (current_node->next == NULL) {
			fprintf(stderr, "Insufficient memory.\n");
			exit(1);
		}
		current_node = current_node->next;
		current_node->item = i, current_node->next = head;
	}

	while (current_node != current_node->next) {
		for (i = 1; i < pos; i++)
			current_node = current_node->next;
		delete_node = current_node->next;
		current_node->next = current_node->next->next;
		free(delete_node);
	}
	printf("The mumber is %d\n", current_node->item);

	return 0;
}

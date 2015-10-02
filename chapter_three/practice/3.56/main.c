#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tnode {	/* the tree node */
	char c;				/* store the character */
	int count;			/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
} Treenode, *Treeptr;

Treeptr addtree(Treeptr p, char c);
void printtree(Treeptr p); 

int
main(int argc, char **argv)
{
	int c;

	Treeptr root = NULL;

	while ((c = getchar()) != EOF) {
		if (isgraph(c)) {
			root = addtree(root, c);
		}
	}

	printtree(root);

	return 0;
}

Treeptr addtree(Treeptr p, char c)
{
	if (p == NULL) {
		p = malloc(sizeof(Treenode));
		p->c = c;
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if (p->c == c) {
		p->count++;
	}
	else if (p->c < c) {
		p->left = addtree(p->left, c);
	}
	else
		p->right = addtree(p->right, c);

	return p;
}

void printtree(Treeptr p) 
{
	if (p != NULL) {
		printf("character '%c' frequence is %d\n", p->c, p->count);
		printtree(p->left);
		printtree(p->right);
	}
}

#include "list.h"
#include <stdlib.h>

link newNode(int x)
{
	link t = malloc(sizeof *t);
	
	t->item = x;
	t->next = t;

	return t;	
}

void freeNode(link x)
{
	free(x);
}

void insertNext(link x, link t)
{
	t->next = x->next;
	x->next = t;	
}

link deleteNext(link x)
{
	link t = x->next;
	x->next = t->next;

	return t;
}

link Next(link x)
{
	return x->next;
}

int Item(link x)
{
	return x->item;
}

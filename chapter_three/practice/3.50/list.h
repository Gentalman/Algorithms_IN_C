#ifndef _LIST_H
#define _LIST_H

typedef int itemType;
typedef struct node* link;
struct node { 
	itemType item; 
	link next; 
};
typedef link Node;

link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);

#endif

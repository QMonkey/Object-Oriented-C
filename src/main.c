#include <stdio.h>

#include "list.h"
#include "queue.h"

int main()
{
	ArrayList *arrayList = newArrayList(1);
	
	int i;
	for(i = 0; i < 10; ++i)
	{
		arrayList->ilist.push(&arrayList->ilist, i);
	}

	for(i = 0; i < 10; ++i)
	{
		printf("%d ", arrayList->ilist.pop(&arrayList->ilist));
	}
	printf("\n");

	deleteArrayList(arrayList);

	LinkedList *linkedList = newLinkedList();

	for(i = 0; i < 10; ++i)
	{
		linkedList->ilist.push(&linkedList->ilist, i);
	}

	for(i = 0; i < 10; ++i)
	{
		printf("%d ", linkedList->ilist.pop(&linkedList->ilist));
	}
	printf("\n");

	deleteLinkedList(linkedList);

	linkedList = newLinkedList();
	LinkedQueue *linkedqueue = newLinkedQueue(&linkedList->ilist);
	for(i = 0; i < 10; ++i)
	{
		linkedqueue->iqueue.add(&linkedqueue->iqueue, i);
	}

	for(i = 0; i < 10; ++i)
	{
		printf("%d ", linkedqueue->iqueue.remove(&linkedqueue->iqueue));
	}
	printf("\n");

	deleteLinkedQueue(linkedqueue);
	deleteLinkedList(linkedList);

	return 0;
}
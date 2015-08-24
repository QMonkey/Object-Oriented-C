#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void LinkedList_push(struct _IList *list, int elem);
static int LinkedList_pop(struct _IList *list);

LinkedList* newLinkedList()
{
	LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	if(linkedList == NULL)
	{
		return NULL;
	}
	linkedList->head = NULL;

	return linkedList;
}

void deleteLinkedList(LinkedList *linkedList)
{
}
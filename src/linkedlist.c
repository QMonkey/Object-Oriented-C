#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void LinkedList_push(IList *list, int elem);
static int LinkedList_pop(IList *list);

LinkedList* newLinkedList()
{
	LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	if(linkedList == NULL)
	{
		return NULL;
	}
	linkedList->head = NULL;

	linkedList->list.push = LinkedList_push;
	linkedList->list.pop = LinkedList_pop;

	return linkedList;
}

void LinkedList_push(IList *list, int elem)
{
	LinkedList *linkedList = container_of(list, LinkedList, list);

	ListNode **node = &linkedList->head;
	while(*node != NULL)
	{
		node = &(*node)->next;
	}

	ListNode *tmpNode = (ListNode*)malloc(sizeof(ListNode));
	tmpNode->value = elem;
	tmpNode->next = NULL;

	*node = tmpNode;
}

int LinkedList_pop(IList *list)
{
	LinkedList *linkedList = container_of(list, LinkedList, list);
	assert(linkedList->head != NULL);

	ListNode *tmp = linkedList->head;
	linkedList->head = tmp->next;

	int value = tmp->value;
	free(tmp);

	return value;
}

void deleteLinkedList(LinkedList *linkedList)
{
	ListNode *tmp = linkedList->head;
	while(linkedList->head != NULL)
	{
		linkedList->head = tmp->next;
		free(tmp);
	}

	free(linkedList);
}
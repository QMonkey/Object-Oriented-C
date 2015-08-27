#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "list.h"
#include "queue.h"

static void LinkedQueue_add(struct _IQueue *queue, int elem);
static int LinkedQueue_remove(struct _IQueue *queue);

LinkedQueue* newLinkedQueue(LinkedList *linkedList)
{
	LinkedQueue *linkedqueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if(linkedqueue == NULL)
	{
		return NULL;
	}
	linkedqueue->linkedList = linkedList;

	linkedqueue->queue.add = LinkedQueue_add;
	linkedqueue->queue.remove = LinkedQueue_remove;

	return linkedqueue;
}

void deleteLinkedQueue(LinkedQueue *queue)
{
	deleteLinkedList(queue->linkedList);
	free(queue);
}

void LinkedQueue_add(struct _IQueue *queue, int elem)
{
	LinkedQueue *linkedQueue = container_of(queue, LinkedQueue, queue);
	LinkedList *linkedList = linkedQueue->linkedList;
	linkedList->list.push(&linkedList->list, elem);
}

int LinkedQueue_remove(struct _IQueue *queue)
{
	LinkedQueue *linkedQueue = container_of(queue, LinkedQueue, queue);
	LinkedList *linkedList = linkedQueue->linkedList;
	return linkedList->list.pop(&linkedList->list);
}
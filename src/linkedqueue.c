#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "list.h"
#include "queue.h"

static void LinkedQueue_add(struct _IQueue *queue, int elem);
static int LinkedQueue_remove(struct _IQueue *queue);

LinkedQueue* newLinkedQueue(IList *list)
{
	LinkedQueue *linkedqueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if(linkedqueue == NULL)
	{
		return NULL;
	}
	linkedqueue->list = list;

	linkedqueue->iqueue.add = LinkedQueue_add;
	linkedqueue->iqueue.remove = LinkedQueue_remove;

	return linkedqueue;
}

void deleteLinkedQueue(LinkedQueue *queue)
{
	free(queue);
}

void LinkedQueue_add(struct _IQueue *queue, int elem)
{
	LinkedQueue *linkedQueue = container_of(queue, LinkedQueue, iqueue);
	linkedQueue->list->push(linkedQueue->list, elem);
}

int LinkedQueue_remove(struct _IQueue *queue)
{
	LinkedQueue *linkedQueue = container_of(queue, LinkedQueue, iqueue);
	return linkedQueue->list->pop(linkedQueue->list);
}
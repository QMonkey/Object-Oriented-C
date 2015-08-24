#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static void ArrayList_push(struct _IList *list, int elem);
static int ArrayList_pop(struct _IList *list);
static void ArrayList_resize(ArrayList *arrayList, size_t size);

ArrayList* newArrayList(size_t size)
{
	if(size <= 0)
	{
		size = 1;
	}

	ArrayList *arrayList = (ArrayList*)malloc(sizeof(ArrayList));
	if(arrayList == NULL)
	{
		return NULL;
	}
	arrayList->_capacity = 0;
	arrayList->_size = size;

	arrayList->_data = (int*)malloc(sizeof(int) * size);

	arrayList->list.push = ArrayList_push;
	arrayList->list.pop = ArrayList_pop;

	return arrayList;
}

void ArrayList_push(struct _IList *list, int elem)
{
	ArrayList *arrayList = container_of(list, ArrayList, list);
	if(arrayList->_capacity == arrayList->_size)
	{
		ArrayList_resize(arrayList, arrayList->_size << 1);
	}
	arrayList->_data[arrayList->_capacity++] = elem;
}

int ArrayList_pop(struct _IList *list)
{
	ArrayList *arrayList = container_of(list, ArrayList, list);
	return arrayList->_data[--arrayList->_capacity];
}

void ArrayList_resize(ArrayList *arrayList, size_t size)
{
	if(size <= arrayList->_size)
	{
		return;
	}

	int *data = (int*)malloc(sizeof(int) * size);

	memcpy(data, arrayList->_data, arrayList->_size * sizeof(int));
	free(arrayList->_data);

	arrayList->_data = data;
	arrayList->_size = size;
}

void deleteArrayList(ArrayList *arrayList)
{
	free(arrayList->_data);
	free(arrayList);
}
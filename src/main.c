#include <stdio.h>

#include "list.h"

int main()
{
	ArrayList *arrayList = newArrayList(1);
	
	int i;
	for(i = 0; i < 10; ++i)
	{
		arrayList->list.push(&arrayList->list, i);
	}

	for(i = 0; i < 10; ++i)
	{
		printf("%d\n", arrayList->list.pop(&arrayList->list));
	}

	deleteArrayList(arrayList);
	return 0;
}
#include <stdio.h>
#include "linkedlist.c"

int main(void)
{
	t_linkedlist* list = NULL;
	int i, count;
	for (i = 0; i < 15; i++)
		list_append(&list, (void*) &i, T_INT);
	
	puts("Items from 0 to 14.");
	for (i = 0; i < 15; i++)
		printf("Item %d = %d\n", i, list_get_int(list, i));
	
	for (i = 0; i < 5; i++)
		list_remove(&list, 0);
	
	count = list_count(list);
	puts("\nItems from 5 to 14.");
	for (i = 0; i < count; i++)
		printf("Item %d = %d\n", i, list_get_int(list, i));
	
	for (i = 0; i < 5; i++)
		list_insert(&list, (void*) &i, T_INT, i);
	
	puts("\nItems from 0 to 14.");
	for (i = 0; i < 15; i++)
		printf("Item %d = %d\n", i, list_get_int(list, i));
	
	puts("\nItems from 14 to 0.");
	for (i = 14; i >= 0; i--)
		list_update(list, (void*) &i, T_INT, 14 - i);
	
	for (i = 0; i < 15; i++)
		printf("Item %d = %d\n", i, list_get_int(list, i));
	
	printf("\nItems in list: %d\n", list_count(list));
	return 0;
}
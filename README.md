C-Linkedlist
============

Simple linkedlist implementation for C language.

## Usage
```c
#include "linkedlist.c"

int main(void)
{
	//Note: initializing the list pointer to NULL is NOT optional
	t_linkedlist* mylist = NULL;
	int value;
	//Now you can do whatever you want with your list
	value = 5;
	//List has to be passed by reference in append function
	//In every function which sets the value of any node in the linkedlist, the value has to be a void* (so it can be a value of any type)
	//Five is appended to the list at index 0
	list_append(&mylist, (void*) &value, T_INT);
	//Some code here
	return 0;
}
```
For more information just check out the header file. Function names are descriptive enough for you to guess what they do.

##Supported types
You can store a value of any type you want but not all of them are treated the same way. If you want to store some C standard types you can use the functions provided by the library to retrieve the items from your list and set them using their respective type constant (`T_INT`, `T_FLOAT`, `T_STRING`, …) otherwise you will have to store them as undefined. Undefined is totally up to you to know what's there and how it has to be treated. You have to set items using `T_UNDEFINED` as the type and retrieve them using `list_get_undef(t_linkedlist* list, int i)`. Of course, you will have to cast the value returned (void*) before using it.

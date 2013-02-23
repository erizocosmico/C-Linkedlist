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


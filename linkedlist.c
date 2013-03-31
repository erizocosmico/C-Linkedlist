/**
 * @file   linkedlist.c
 * @author José Miguel Molina (hi@mvader.me)
 * @version 1.2
 * @date   February, 2013
 * @brief  Provides an implementation for the functions defined in linkedlist.h.
 * @license MIT License
 * Copyright (C) 2013 José Miguel Molina
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @description This file provides an implementation for the functions that were defined in the
 * header file linkedlist.h. Those functions provide functionalities like appending, 
 * inserting, removing, retrieving and updating items from a linkedlist.
 */

#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void list_assign_value(t_linkedlist* node, void* value, size_t size)
{
	node->value = malloc(size);
	memmove((void*) node->value, (const void*) value, (size_t) size);
}

void list_append(t_linkedlist** list, void* value, size_t size)
{
	t_linkedlist *ptr, *ptraux;
	ptr = *list;

	if (ptr == NULL)
	{
		ptr = (t_linkedlist*) malloc(sizeof(t_linkedlist));
		if (ptr != NULL)
		{
			list_assign_value(ptr, value, size);
			ptr->link = NULL;
			*list = ptr;
		}
	}
	else
	{
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptraux = (t_linkedlist*) malloc(sizeof(t_linkedlist));
		if (ptraux != NULL)
		{
			list_assign_value(ptraux, value, size);
			ptraux->link = NULL;
			ptr->link = ptraux;
		}
	}
}

void list_insert(t_linkedlist** list, void* value, size_t size, int i)
{
	t_linkedlist *ptr, *ptraux, *ptraux2;
	int j = 0;
	ptr = *list;

	if (ptr == NULL)
		list_append(list, value, size);
	else
	{
		if (!i)
		{
			ptraux = (t_linkedlist*) malloc(sizeof(t_linkedlist));
			list_assign_value(ptraux, value, size);
			ptraux->link = ptr;
			*list = ptraux;
		}
		else
		{
			while (ptr->link != NULL)
			{
				j++;
				if (j == i)
				{
					ptraux = ptr->link;
					ptraux2 = (t_linkedlist*) malloc(sizeof(t_linkedlist));
					list_assign_value(ptraux2, value, size);
					ptr->link = ptraux2;
					ptraux2->link = ptraux;
					break;
				}
				else
					ptr = ptr->link;
			}
		}
	}
}

t_linkedlist* list_get_node(t_linkedlist* list, int i)
{
	t_linkedlist* ptr = list;
	int j = 0;
	if (ptr == NULL)
		return NULL;
	else
	{
		if (!i)
			return ptr;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
			j++;
			if (j == i)
				break;
		}
		return ptr;
	}
}

int list_count(t_linkedlist* list)
{
	int i = 0;
	t_linkedlist* ptr = list;
	if (list != NULL)
	{
		i++;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
			i++;
		}
	}
	return i;
}

void* list_get(t_linkedlist* list, int i)
{
	return list_get_node(list, i)->value;
}

short list_get_short(t_linkedlist* list, int i)
{
	return *((short*) list_get_node(list, i)->value);
}

int list_get_int(t_linkedlist* list, int i)
{
	return *((int*) list_get_node(list, i)->value);
}

float list_get_float(t_linkedlist* list, int i)
{
	return *((float*) list_get_node(list, i)->value);
}

double list_get_double(t_linkedlist* list, int i)
{
	return *((double*) list_get_node(list, i)->value);
}

char list_get_char(t_linkedlist* list, int i)
{
	return *((char*) list_get_node(list, i)->value);
}

char* list_get_str(t_linkedlist* list, int i)
{
	return (char*) list_get_node(list, i)->value;
}

long list_get_long(t_linkedlist* list, int i)
{
	return *((long*) list_get_node(list, i)->value);
}

void list_remove(t_linkedlist** list, int i)
{
	t_linkedlist *ptr, *ptraux;
	ptr = *list;
	int j = 0;
	if (ptr != NULL)
	{
		if (!i)
		{
			if (ptr->link == NULL)
				*list = NULL;
			else
				*list = ptr->link;
			free(ptr);
		}
		else
		{
			while (ptr->link != NULL)
			{
				j++;
				if (j == i)
				{
					ptraux = ptr->link;
					ptr->link = ptraux->link;
					free(ptraux);
					break;
				}
				else
					ptr = ptr->link;
			}
		}
	}
}

void list_update(t_linkedlist* list, void* value, size_t size, int i)
{
	t_linkedlist* ptr = list_get_node(list, i);
	list_assign_value(ptr, value, size);
}

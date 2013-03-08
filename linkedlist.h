/**
 * @file   linkedlist.h
 * @author José Miguel Molina (rd4091@gmail.com)
 * @version 1.2
 * @date   February, 2013
 * @brief  Declaration of linkedlist types and function prototypes.
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
 * @description In this file are declared the three types used by the linkedlist, the constants to
 * access the linkedlist value types and the prototypes of the functions that will
 * be implemented in linkedlist.c.
 */

typedef struct node {
	void* value;
	struct node* link;
} t_linkedlist;

extern void list_assign_value(t_linkedlist* node, void* value, size_t size);
extern void list_append(t_linkedlist** list, void* value, size_t size);
extern void list_insert(t_linkedlist** list, void* value, size_t size, int i);
extern int list_count(t_linkedlist* list);
extern void* list_get(t_linkedlist* list, int i);
extern short list_get_short(t_linkedlist* list, int i);
extern int list_get_int(t_linkedlist* list, int i);
extern float list_get_float(t_linkedlist* list, int i);
extern double list_get_double(t_linkedlist* list, int i);
extern char list_get_char(t_linkedlist* list, int i);
extern char* list_get_str(t_linkedlist* list, int i);
extern long list_get_long(t_linkedlist* list, int i);
extern void* list_get_undef(t_linkedlist* list, int i);
extern void list_remove(t_linkedlist** list, int i);
extern void list_update(t_linkedlist* list, void* value, size_t size, int i);

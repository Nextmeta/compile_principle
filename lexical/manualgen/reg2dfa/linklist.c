/*
 * file name: linklist.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 08:43:03 AM CST
 */

#include "linklist.h"
#include "allocate.h"

#define T 	LL

struct T {
	dtype_t elem;
	T 	next; 
};

T LL_new()
{
	T t;
	t = NEW(t);
	t->elem = 0;
	t->next = NULL;
	return t;
}
int LL_is_empty(T list)
{
	return list->next == NULL;
}

int LL_is_last(T list, T pos)
{
	return pos->next == NULL;
}

T LL_find(T list, dtype_t x)
{
	T pos;
	pos = list->next;
	while (pos != NULL && pos->elem != x)
		pos = pos->next;
	return pos;
}

void LL_remove(T list, dtype_t x)
{
	T prev, tmpnode;
	prev = LL_find_prev(list, x);
	if (!LL_is_last(list, prev)) {
		tmpnode = prev->next;
		prev->next = tmpnode->next;
		free(tmpnode);
	}
}

void LL_insert(T list, T pos, dtype_t x)
{
	T tmpnode;
	tmpnode = NEW(tmpnode);
	if (tmpnode == NULL)
		raise_exception(MEMORY_EXCEPTION, 
				"allocate failed");
	tmpnode->elem = x;
	tmpnode->next = pos->next;
	pos->next = tmpnode;
}
T LL_find_prev(T list, dtype_t x)
{
	T pos;
	pos = list;
	while (pos->next != NULL && pos->next->elem != x)
		pos = pos->next;
	return pos;
}

void LL_delete(T list)
{
	T pos, tmpnode;
	pos = list->next;
	list->next = NULL;
	while (pos != NULL) {
		tmpnode = pos->next;
		free(pos);
		pos = tmpnode;
	}
}

T LL_next(T pos)
{
	return pos->next;
}

T LL_get_header(T list)
{
	assert(list);
	return list;
}

T LL_get_first(T list)
{
	assert(list);
	return list->next; 
}

dtype_t LL_getmin(T list)
{
	dtype_t min;
	LL curr = LL_next(list);
	min = LL_retrieve(curr);
	while (curr != NULL) {
		int tmp = LL_retrieve(curr);
		if (tmp < min)
			min = tmp;
		curr = curr->next;
	}
	return min;
}
dtype_t LL_retrieve(T pos)
{
	assert(pos);
	return pos->elem;
}

void LL_prints(T list)
{
	T tmpnode;
	tmpnode = list->next;
	while (tmpnode != NULL) {
		printf("%d ", tmpnode->elem);
		tmpnode = tmpnode->next;
	}
	free(tmpnode);
}


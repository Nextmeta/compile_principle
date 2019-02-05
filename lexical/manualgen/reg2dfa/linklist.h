/*
 * file name: linklist.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 08:29:42 AM CST
 */

#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdlib.h>
#include <assert.h>

typedef int dtype_t; 
#define T	LL 
typedef struct T *T;

/* @list: List being looked up
 * @pos : Tracked node 
 * @x   : Element to insert
 */

extern T 	LL_new();
extern T	LL_make_empty(T list);
extern int      LL_is_empty(T list);
extern int      LL_is_last(T list, T pos);
extern T        LL_find(T list, dtype_t x);
extern void     LL_remove(T list, dtype_t x);
extern T	LL_find_prev(T list, dtype_t x);
extern void     LL_insert(T list, T pos, dtype_t x);
extern void 	LL_delete(T list);
extern T	LL_get_header(T list);
extern T	LL_get_first(T list);
extern dtype_t 	LL_retrieve(T pos);
extern void     LL_prints(T list);
extern T	LL_next(T pos);
extern dtype_t  LL_getmin(T list);
#undef T

#endif

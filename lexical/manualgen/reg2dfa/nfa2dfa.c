/*
 * file name: nfa2dfa.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 04 Feb 2019 12:11:34 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linklist.h"
#include "stack.h"

#define NFA_STATES 	11
#define ALPHA_NUM 	3
/* NFA: (a|b)*abb */

Stack old_states;
char already_on[NFA_STATES];	/* Which states already in new_states */
LL nfa_trans[NFA_STATES][ALPHA_NUM];
LL dfa_trans[NFA_STATES][ALPHA_NUM];

int F = 10;		/* Terminate status */
#define NFA_ROWCOL(x, y, d) LL_insert(nfa_trans[x][y], nfa_trans[x][y], d)

void build_nfa();
LL e_closure(LL t);
LL move(LL m, int c);
void build_subset();
int main(void)
{
	LL S,S0 = LL_new();
	old_states = STK_new();
	printf("NFA tables: \n");
	build_nfa();
	LL_insert(S0, S0, 0);
	S = e_closure(S0);
	/* NFA 2 DFA tables 
	LL DStates[1024];
	DStates[0] = S;
	int i, j, k, flag = 0;
	for (i = 0; i < NFA_STATES; i++) {
		int l = i;
		while (l <= flag) {
			already_on[l] = 'A' + l;
			l++;
		}
		for (j = 0; j < 2; j++) {
			LL U = e_closure(move(DStates[i], 'a' + j));
			for (k = 0; k < i; k++) {
				if (DStates[k] == U)
					break;
			}
			if (k == i) {
				flag++;
				DStates[flag] = U;
			}
			dfa_trans[i][j] = U;
		}
	}
	for (i = 0; i < NFA_STATES; i++) {
		printf("%c", already_on[i]);
	}
	*/
	/* On-the-fly(边构造边使用)  */
	S = e_closure(S0);
	char c = getchar();
	while (c != '\n') {
		S = e_closure(move(S, c));
		c = getchar();
	}
	if (LL_find(S, F))
		printf("Matched\n");
	else
		printf("Not matched\n");
	return 0;
}

void build_nfa()
{
	int i, j;
	for (i = 0; i < NFA_STATES; i++)
		for (j = 0; j < ALPHA_NUM; j++) 
			nfa_trans[i][j] = LL_new();
	/* build test nfa (a|b)*abb */
	/* Inserted transgraph */

	NFA_ROWCOL(0, 2, 7);
	NFA_ROWCOL(0, 2, 1);

	NFA_ROWCOL(1, 2, 4);
	NFA_ROWCOL(1, 2, 2);

	NFA_ROWCOL(2, 0, 3);
	
	NFA_ROWCOL(3, 2, 6);

	NFA_ROWCOL(4, 1, 5);
	
	NFA_ROWCOL(5, 2, 6);

	NFA_ROWCOL(6, 2, 7);
	NFA_ROWCOL(6, 2, 1);
	
	NFA_ROWCOL(7, 0, 8);

	NFA_ROWCOL(8, 1, 9);

	NFA_ROWCOL(9, 1, 10);

	printf("%9c\t%-2c\t\u0395\n", 'a', 'b');
	for (i = 0; i < NFA_STATES; i++) {
		printf("%-2d\t", i);
		for (j = 0; j < ALPHA_NUM; j++) {
			LL curr = LL_next(nfa_trans[i][j]);
			if (curr == NULL)
				printf("\u03A6");
			else {
				while (curr != NULL) {
					printf("%d, ", LL_retrieve(curr));
					curr = LL_next(curr);
				}
			}
			putchar('\t');
		}
		printf("\n"); 
	}
}

LL e_closure(LL t)
{
	LL curr = LL_next(t);
	LL closure_T = LL_new();
	int i;
	for (i = 0; i < NFA_STATES; i++)
		already_on[i] = false;
	
	while (curr != NULL) {
		/* add states into stack of old_states */
		int s = LL_retrieve(curr);
		STK_push(old_states, s);
		LL_insert(closure_T, closure_T, s);
		curr = LL_next(curr);
	}
	while (!STK_is_empty(old_states)) {
		int top = STK_pop(old_states);
		LL tmp = LL_next(nfa_trans[top][2]);
		while (tmp != NULL) {
			int u = LL_retrieve(tmp);
			if (!LL_find(closure_T, u)) {
				LL_insert(closure_T, closure_T, u);
				STK_push(old_states, u);
			}
			tmp = LL_next(tmp);
		}
	}
	return closure_T;
}

LL move(LL m, int c)
{
	LL curr = LL_next(m);
	LL newset = LL_new();
	while (curr != NULL) {
		int s = LL_retrieve(curr);
		LL tmp;
		switch (c) {
		case 'a':
			tmp = LL_next(nfa_trans[s][0]);
			break;
		case 'b':
			tmp = LL_next(nfa_trans[s][1]);
			break;
		default:
			tmp = LL_next(nfa_trans[s][2]);
			break;
		}
		while (tmp != NULL) {
			LL_insert(newset, newset, LL_retrieve(tmp));
			tmp = LL_next(tmp);
		}
		curr = LL_next(curr);
	}
	return newset;
}

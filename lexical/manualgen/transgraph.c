/*
 * file name: transgraph.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 20 Dec 2018 11:24:02 AM CST
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Regular expression: (a|b)*aab */

#define NONE 		-1
#define NTERMSTAT	1

/* DFA translate table */
int dfa_tab[4][2] = {
/* state 0 */	{1, 0,},
/* state 1 */ 	{1, 2,},
/* state 2 */	{1, 3,},
/* state 3 */	{1, 0,},
};
int F[NTERMSTAT] = {3};

int move(int state, char c);
int main(void)
{
	int start = 0;
	int state = start;
	int c = getchar();
	int i;
	printf("%d->", state);
	while (c != '\n') {
		state = move(state, c);
		c = getchar();
		printf("%d->", state);

	}
	for (i = 0; i < NTERMSTAT; i++) {
		if (F[i] == state) {
			printf("Recieve\n");
			break;
		}
	}
	if (i == NTERMSTAT)
		printf("Failed\n");
	return 0;
}
int move(int state, char c)
{
	int idx;
	if (c == 'a')
		idx = 0;
	else if (c == 'b')
		idx = 1;
	else
		idx = -1;
	if (idx == -1)
		return -1;
	return dfa_tab[state][idx];
}

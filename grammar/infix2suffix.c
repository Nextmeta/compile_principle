/*
 * file name: infix2suffix.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 14 Dec 2018 12:08:02 AM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lookahead;

void expr();
void rest();
void term();
void match(int t_symbolic);
void error();

int main(void)
{
	expr();
	putchar('\n');
	exit(0);
}

void expr()
{
	lookahead = getchar();
	term();
	rest();
}
void term()
{
	if (isdigit(lookahead)) {
		putchar(lookahead);
		match(lookahead);
	} else {
		error();
	}
}
void rest()
{
L1:
	switch (lookahead) {
	case '+':
		match('+');
		term();
		putchar('+');
		break;
	case '-':
		match('-');
		term();
		putchar('-');
		break;
	default:
		error();
	}
	goto L1;
}
void match(int t_symbolic)
{
	if (lookahead == t_symbolic)
		lookahead = getchar();
	else
		error();
}
void error()
{
	fprintf(stderr, "Syntax error\n");
	exit(-1);
}

/*
 * file name: main.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 22 Dec 2018 12:26:57 AM CST
 */

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
int main(void)
{
	int tok = yylex();
	printf("Tok = %d\n", tok);
	exit(0);
}

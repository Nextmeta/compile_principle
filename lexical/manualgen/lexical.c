/*
 * file name: lexical.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 14 Dec 2018 10:30:43 AM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"

int lineno = 1;
int tokval = NONE;
char lexbuf[BUFSIZ];

int lexan();
int main(void)
{
	int tok = lexan();
	if (tok == ID) {
		printf("ID: %s\n", lexbuf);
	} else if (tok == NUM) {
		printf("NUM: %d\n", tokval);
	} else {
		printf("Not implementation!\n");
	}
	exit(0);
}
int lexan()
{
	int t;
	while (1) {
		t = getchar();
		if (t == ' ' || t == '\t') {
			;
		} else if (t == '\n') {
			lineno += 1;
		} else if (isdigit(t)) {
			tokval = t - '0';
			t = getchar();
			while (isdigit(t)) {
				tokval = tokval * 10 + t - '0';
				t = getchar();
			}
			ungetc(t, stdin);
			return NUM;
		} else if (isalpha(t)) {
			int trace = 0;
			lexbuf[trace] = t;
			while (isalnum(t)) {
				trace++;
				t = getchar();
				lexbuf[trace] = t;
			}
			lexbuf[trace] = '\0';
			ungetc(t, stdin);
			return ID;
		} 
		else {
			tokval = NONE;
			return t;
		}
	}
}

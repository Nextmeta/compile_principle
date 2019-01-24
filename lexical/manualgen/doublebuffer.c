/*
 * file name: doublebuffer.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 21 Jan 2019 01:38:30 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N	5

char lexbuf1[N];
char lexbuf2[N];

#define EOS 	'$'
int main(void)
{
	char *lexemebegin, *forward;
	char *flag;
	int n = read(1, lexbuf1, N);
	lexbuf1[n - 1] = EOF;
	lexemebegin = forward = lexbuf1;
	flag = lexbuf1;
	while (*forward) {
		if (*forward == EOF) {
			if (flag == lexbuf1) {
				printf("1: %s\n", lexbuf1);
				memset(lexbuf2, 0, N);
				n = read(1, lexbuf2, N);	
				lexbuf2[n - 1] = EOF;
				forward = lexbuf2;
				flag = lexbuf2;
			} else {
				printf("2: %s\n", lexbuf2);
				memset(lexbuf1, 0, N);
				n = read(1, lexbuf1, N);
				lexbuf1[n - 1] = EOF;
				forward = lexbuf1;
				flag    = lexbuf1;
			}
		}
		forward++;
	}
	return 0;
}

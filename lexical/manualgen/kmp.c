/*
 * file name: kmp.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 11:32:24 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal_invalid_func(const char *keyowrd, int f[], int len);
void print_invalid_func(int *f, int len);

int main(void)
{
	char *key = "ababaa";
	char *key1 = "abababaab";
	char *key2 = "aaaaaa";
	char *key3 = "abbaabb";

	int len   = strlen(key);
	int len1  = strlen(key1);
	int len2  = strlen(key2);
	int len3  = strlen(key3);

	int  *f   = (int*) malloc(sizeof(int) * len);
	cal_invalid_func(key, f, len);
	print_invalid_func(f, len);
	
	int *f1   = (int*) malloc(sizeof(int) * len1);
	cal_invalid_func(key1, f1, len1);
	print_invalid_func(f1, len1);
	
	int *f2   = (int*) malloc(sizeof(int) * len2);
	cal_invalid_func(key2, f2, len2);
	print_invalid_func(f2, len2);
	
	int *f3   = (int*) malloc(sizeof(int) * len3);
	cal_invalid_func(key3, f3, len3);
	print_invalid_func(f3, len3);
	
	free(f3);	
	free(f2);	
	free(f1);	
	free(f);	
	return 0;

}

void cal_invalid_func(const char *keyword, int *f, int len)
{
	int t = 0;
	*f    = 0;
	int i;
	for (i = 1; i < len; i++) {
		while (t > 0 && keyword[i] != keyword[t]) t = f[t - 1];
		if (keyword[i] == keyword[t]) {
			t++;
			f[i] = t;
		} else f[i] = 0;
	}
}

void print_invalid_func(int *f, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", *(f + i));
	putchar('\n');
}

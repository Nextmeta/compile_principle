/*
 * file name: relopgraph.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 26 Jan 2019 10:54:16 PM CST
 */

#include <stdio.h>
#include <stdlib.h>

#define TOKEN 		int 
#define nextchar() 	getchar()
#define retract() 	ungetc(c, stdin)

enum {
	LT = 256, LE, NE, EQ, GE, GT,	
};

void fail()
{
	printf("Not this transgraph\n");
	exit(-1);
}
TOKEN get_relop()
{
	TOKEN ret;
	int state = 0;
	char c;
	while (1) {
		switch (state) {
		case 0:
			c = nextchar();
			if (c == '<') state = 1;
			else if (c == '=') state = 5;
			else if (c == '>') state = 6;
			else fail();
			break;
		case 1:
			c = nextchar();
			if (c == '=') state = 2;
			else if (c == '>') state = 3;
			else state = 4;
			break;
		case 2:
			ret = LE;
			goto out;
		case 3:
			ret = NE;
			goto out;
		case 4:
			ret = LT;
			retract();
			goto out;
		case 5:
			ret = EQ;
			goto out;
		case 6:
			c = nextchar();
			if (c == '=') state = 7;
			else state = 8;
			break;
		case 7:
			ret = GE;
			goto out;
		case 8:
			ret = GT;
			retract();
			goto out;
		}	
	}
out:
	return ret;
}

int main(void)
{
	int tok = get_relop();
	switch (tok) {
	case LT:
		printf("LT\n");
		break;
	case LE:
		printf("LE\n");
		break;
	case NE:
		printf("NE\n");
		break;
	case EQ:
		printf("EQ\n");
		break;
	case GE:
		printf("GE\n");
		break;
	case GT:
		printf("GT\n");
		break;
	}	
	return 0;
}

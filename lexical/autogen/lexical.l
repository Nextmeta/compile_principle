%{
#include <stdio.h>
#include "token.h"

int yywrap()
{
	return 1;
}
%}

delim		[ \t\n]
letter		[a-zA-Z]
digit		[0-9]
id		{letter}({letter}|{digit})*
ws 		{delim}+
number 		{digit}+

digits		{digit}+
opt_fraction 	\.{digits}
opt_exponet 	([E|e][+|-]{digits})
float 		{digits}*{opt_fraction}
exponet 	{digits}{opt_fraction}?{opt_exponet}
%%

{ws}		{} 
{number}	{printf("NUMBER\n"); return NUM;}
{id}		{printf("ID\n"); return ID;}
{float} 	{printf("FLOAT\n"); return FLOAT;}
{exponet}	{printf("EXPONET\n");}


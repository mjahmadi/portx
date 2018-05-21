#ifndef _HELPERS_H
#define _HELPERS_H


char *_inttostr (int a)
{
	char *str = malloc(sizeof(char)*20);
	sprintf(str, "%d", a);
	
	return str;
}


#endif //_HELPERS_H


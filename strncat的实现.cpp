//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
#include <assert.h>

char* HH_strncat(char *dest, const char *src, size_t n)
{
	char *ret = dest;

	while (*dest){
		dest++;
	}

	// TODO: 这不跟strcat一样？？
	while (n--){
		*dest++ = *src++;
	}

	return ret;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char sz[5];
	memset(&sz, 0, 5);
	sz[0]= '1';

	HH_strncat(sz, "234",1);
	//strncat(sz, "234",3);
	printf("%s", sz);


	return 0;
}
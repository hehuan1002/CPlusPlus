// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <string.h>

char* HH_strcpy(char *dst, const char* src)
{
	/*assert(dst);
	assert(src);
	char* s = dst;
	while (*s++ = *src++)
	;
	return dst;*/

	// Error: 错误方式的拷贝，不理解
	assert(dst);
	assert(src);
	while (*dst++ = *src++)
		;
	return dst;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char data[5];
	memset(data, 0, 5);
	char* sz =  HH_strcpy(data, "333");

	return 0;
}
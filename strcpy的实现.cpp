// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
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

	// Error: ����ʽ�Ŀ����������
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
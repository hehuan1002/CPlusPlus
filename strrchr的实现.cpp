// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>

char* HH_strrchr(const char* str, int ch)
{
	assert(str);
	char* s = (char*)str;
	while(*s != '\0')
		s++;

	while(s != str && *s != ch)
		s--;

	if (*s == ch)
		return s;

	return NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char* test1 = HH_strrchr("abcdef", 'z');
	char* test2 = HH_strrchr("abcedf", 'f');
	return 0;
}
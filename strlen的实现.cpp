// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <assert.h>

int HH_strlen(const char* str)
{
	assert(str);
	char* s = (char*)str;
	int len = 0;
	while(*s != '\0')
	{
		s++;
		len++;
	}
		
	return len;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int len1 = HH_strlen("abcdef");
	int len2 = HH_strlen("");

	// Error: ����Ľ��������3����Ϊ����û����'\0'��β��
	char sz[3];
	sz[0] = 'a';
	sz[1] = 'b';
	sz[2] = 'c';
	int len3 = HH_strlen(sz); 


	// 
	char data[3] = { 'a', 'b', '\0'};
	int len4 = HH_strlen(data);

	// �����ַ���ĩβ�Զ���'\0'
	char *dddd = "1234";
	int len5 = HH_strlen(dddd);

	return 0;
}
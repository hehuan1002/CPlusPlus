// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <assert.h>
#include <string.h>

char* HH_strcpy(char *dst, const char* src)
{
	assert(dst);
	assert(src);
	char* s = dst;// s����ʱ��ָ�����������ѭ���Ľ��У���ַһֱ�ڱ䣬ֱ��ѭ��������s�ĵ�ַ��0x006c6338�仯��0x006c633c��
	while (*s++ = *src++)
		;
	return dst; // ���봫���׵�ַ����



	//Error: ����ʽ�Ŀ���������⣬�ѵ���������׵�ַ
	//assert(dst);
	//assert(src);
	//while (*dst++ = *src++)
		;
	//return dst; ����ѭ���Ľ��У�dst��ַһֱ�ڷ����仯��return dst�Ͳ��Ƿ����׵�ַ�ˡ�
}
int _tmain(int argc, _TCHAR* argv[])
{
	char data[5];
	memset(data, 0, 5);
	char* sz =  HH_strcpy(data, "333");

	return 0;
}
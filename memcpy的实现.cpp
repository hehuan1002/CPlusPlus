//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <memory.h>
#include <assert.h>

void* HH_memcpy(void* dst, void* src, size_t count)
{
	// ��׼д��
	void *ret = dst;
	while (count--){
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}

	return dst;

}
int _tmain(int argc, _TCHAR* argv[])
{
	char sz[5];
	memset(&sz, 0, 5);

	// ����4���ֽڵ�sz����dst����src����ΪNULL����Ȼ�����������ĳ�����count������
	// dst��src��ָ���ڴ��������ص�������ص��ͻᷢ���������⣬��������ָ��dst��ָ�롣
	// ��strcpy��ȣ�memcpy����������'\0'�ͽ����ˣ�����һ���´����count���ֽڡ�
	// �ڿ�����ʱ�򣬶���ת����char*����Ϊ��������һ���ֽ�һ���ֽڿ����ģ�����ʵ�ʲ�����ʱ��Ҫ��void*ǿ��ת��Ϊchar*��������ָ��ӵ�ʱ��Żᱣ֤ÿ�μ�һ���ֽڡ�
	HH_memcpy(sz, "1234", 4);
	
	printf("%s", sz);
	return 0;
}
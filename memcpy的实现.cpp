//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
#include <assert.h>

void* HH_memcpy(void* dst, void* src, size_t count)
{
	// 标准写法
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

	// 拷贝4个字节到sz，当dst或者src传入为NULL，必然崩溃，拷贝的长度由count决定。
	// dst和src所指的内存区域不能重叠，如果重叠就会发生拷贝问题，函数返回指向dst的指针。
	// 与strcpy相比，memcpy并不是遇到'\0'就结束了，而是一定会拷贝完count个字节。
	// 在拷贝的时候，都是转换成char*，因为函数都是一个字节一个字节拷贝的，所以实际操作的时候要把void*强制转化为char*，这样在指针加的时候才会保证每次加一个字节。
	HH_memcpy(sz, "1234", 4);
	
	printf("%s", sz);
	return 0;
}
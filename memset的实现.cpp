//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
struct TKUSERREQHEMATINIC
{
	int n;
	int m;
};


void * __cdecl tk_memset(
	void *dst,
	int val,
	size_t count
	)
{
	char *start = (char*)dst;
	while (count--) // count表示是字节
	{
		*start = (char)val;
		start = start + 1;
	}

	return dst;
}

void testTK_memset_0()
{
	int a[5][5];
	for (int i(0); i <= 4; ++i){
		for (int j(0); j <= 4; ++j){
			a[i][j] = 10;
		}
	}

	memset(a, 0, sizeof(a));

	for (int i(0); i <= 4; ++i)
	{
		for (int j(0); j <= 4; ++j)
			printf ("%d ", a[i][j]);
		printf ("\n");
	}
}


void testTK_memset_1()
{
	int a[5][5];

	for (int i = 0; i <= 4; ++i)
		for (int j = 0; j <= 4; ++j)
			a[i][j] = 10;

	memset(a, 1, sizeof(a));

	for (int i(0); i <= 4; ++i)
	{
		for (int j(0); j <= 4; ++j)
			printf ("%d ", a[i][j]);
		printf ("\n");
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	TKUSERREQHEMATINIC stAck;
	tk_memset(&stAck, 0, sizeof(stAck));


	// 输出为0，毕竟0的每个字节都是0。
	testTK_memset_0();
	
	// 输出16843009,并不是期望中的1，主要原因：memset是逐字节拷贝的。int的每个字节都会赋值为1，1的二进制为00000001，
	//所以in值变成了0x00000001 0x00000001 0x00000001 0x00000001，把这4个字节用十进制输出的话
	// 就是16843009，用十六进制输出的话就是0X01010101。 所以用memset初始化的时候建议用0或者-1。
	testTK_memset_1();

	return 0;
}
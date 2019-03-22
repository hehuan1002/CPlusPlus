//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
struct TKUSERREQHEMATINIC
{
	int n;
	int m;
};


void * __cdecl tk_memset (
	void *dst,
	int val,
	size_t count
	)
{
	char *start = (char*)dst;

#if defined (_M_IA64) || defined (_M_AMD64)

	{


		__declspec(dllimport)


			void RtlFillMemory( void *, size_t count, char );

		RtlFillMemory( dst, count, (char)val );

	}

#else  /* defined (_M_IA64) || defined (_M_AMD64) */
	while (count--) {
		*start = (char)val;
		start = start + 1;
	}
#endif  /* defined (_M_IA64) || defined (_M_AMD64) */

	return(dst); // 返回首地址
}

int _tmain(int argc, _TCHAR* argv[])
{
	TKUSERREQHEMATINIC stAck;
	tk_memset(&stAck, 0, sizeof(stAck));


	//https://blog.csdn.net/qq_42592097/article/details/81947072 

	return 0;
}


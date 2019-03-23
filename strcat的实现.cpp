//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory.h>
#include <assert.h>

char * HH_strcat (char *dst, const char *src)
{
	char* ret = dst;

	// find end of det
	while (*dst){
		dst++;
	}

	// 有问题的代码,因为此时*dst = 0，所以下面代码不会执行
	/*while (*dst && *src){
		*dst++ = *src++;
	}*/

	while (*dst++ = *src++)
		;

	// 等同于如下
	/*while (*dst = *src){
		dst++;
		src++;
	}*/

	// 汇编指令如下：
	/*
	0098142B  mov         eax,dword ptr [dst]  
	0098142E  mov         ecx,dword ptr [src]  
	00981431  mov         dl,byte ptr [ecx]  
	00981433  mov         byte ptr [eax],dl  
	00981435  mov         eax,dword ptr [dst]  
	00981438  mov         cl,byte ptr [eax]  
	0098143A  mov         byte ptr [ebp-0CDh],cl  
	00981440  mov         edx,dword ptr [dst]  
	00981443  add         edx,1  
	00981446  mov         dword ptr [dst],edx  
	00981449  mov         eax,dword ptr [src]  
	0098144C  add         eax,1  
	0098144F  mov         dword ptr [src],eax  
	00981452  movsx       ecx,byte ptr [ebp-0CDh]  
	00981459  test        ecx,ecx  
	0098145B  je          HH_strcat+9Fh (98145Fh) 
	;
	0098145D  jmp         HH_strcat+6Bh (98142Bh)  */

	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char sz[5];
	memset(&sz, 0, 5);
	sz[0]= '1';

	
	HH_strcat(sz, "234");
	printf("%s", sz);
	return 0;
}
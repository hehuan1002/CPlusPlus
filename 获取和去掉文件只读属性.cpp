// TestDDD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char szFilePath[MAX_PATH] = "D:\\hehuan.txt";
	DWORD n1 = ::GetFileAttributesA(szFilePath);
	if (n1&FILE_ATTRIBUTE_READONLY)
	{
		int n2 = n1&~FILE_ATTRIBUTE_READONLY;
		BOOL n3 = ::SetFileAttributesA(szFilePath, n2);
		int n4 = ::GetFileAttributesA(szFilePath);

		int nd=0;
	}

	// 当hehuan.txt有只读属性时，n1=33，当去掉只读属性时，n4=32。查看文件属性时，只读没有了。
	return 0;
}

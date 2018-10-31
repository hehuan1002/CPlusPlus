// Test_critical_section.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ObjectLock.h"
CAutoLock autoLock;

int _tmain(int argc, _TCHAR* argv[])
{
	CObjectLock lock(&autoLock);
	return 0;
}


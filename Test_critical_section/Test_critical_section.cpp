// Test_critical_section.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ObjectLock.h"
CAutoLock autoLock;

int _tmain(int argc, _TCHAR* argv[])
{
	CObjectLock lock(&autoLock);
	return 0;
}


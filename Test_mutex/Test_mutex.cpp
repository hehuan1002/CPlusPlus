// Win32Project1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LockGuard.h"
std::mutex g_m;

int TestLockGuid()
{
	return 1;
}

void f()
{
	return ;
}

bool everything_ok()
{
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CLockGuard lg(g_m); // RAII �ࣺ����ʱ���������������
	f(); // �� f() ���쳣�����ͷŻ���
	if (!everything_ok()) return 1;  // ���緵�أ�LockGuard ����ʱ�����������ͷ�
	                                 // �� main() �������أ����ͷŻ���
	return 0;
}


// Win32Project1.cpp : 定义控制台应用程序的入口点。
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
	CLockGuard lg(g_m); // RAII 类：构造时，互斥量请求加锁
	f(); // 若 f() 抛异常，则释放互斥
	if (!everything_ok()) return 1;  // 提早返回，LockGuard 析构时，互斥量被释放
	                                 // 若 main() 正常返回，则释放互斥
	return 0;
}


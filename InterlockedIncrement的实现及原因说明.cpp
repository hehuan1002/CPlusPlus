// Testdddddd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

LONG load_link(LONG volatile *value)
{
	LONG lValue = 0;
	return lValue;
}

BOOL store_contional(LONG volatile *lOriginal, LONG volatile *lNewValue)
{
	return TRUE;
}

//load_link指令从内存读取一个字，放到一个寄存器，以实现接下来的(Read-Modify-Write)操作
//store_contional指令是把一个字写入内存当中，如果此时发现此快内存的值有修改过，就返回失败，继续执行load_link操作。

//这对于需要用汇编语言来实现Interlocked操作的你来说意味着什么？你需要尽可能减少load-link和store-conditional之间的指令数。
//例如，InterlockedIncrement只不过是给值加1。你在load-link和store-conditional之间插入的指令越多，store-conditional失败的可能就越大，你就不得不重来一次。
//如果你在两者之间插入的指令太多了就会导致store-conditional永远不会成功。
//举一个极端的例子，如果你计算新值的代码需要耗时5秒，在这5秒内肯定会接收到很多硬件中断，store-conditional操作就永远都会失败。
// 英文链接：https://blogs.msdn.microsoft.com/oldnewthing/20130913-00/?p=3243/
LONG HH_InterlockedIncrement(LONG volatile *value)
{
	LONG lOriginal, lNewValue;
	do 
	{
		// Read the current value via load-link so we will know if
		// somebody has modified it while we weren't looking.
		lOriginal = load_link(value);

		 // Calculate the new value
		lNewValue = lOriginal +1;

		// Store the value conditionally. This will fail if somebody
		// has updated the value in the meantime.
	} while (!store_contional(&lOriginal, &lNewValue));

	return lNewValue;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LONG i = 0;
	HH_InterlockedIncrement(&i);
	return 0;
}

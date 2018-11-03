// Test_pragma.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>



//#pragma warning(disable:4005;once:4005;error:4005) // 一连串的操作，等于三条命令#pragma warning(disable:4005)，#pragma warning(once:4005)，#pragma warning(error:4005)
//#pragma warning(disable:4005) // 在编译的时候，屏蔽警告C4005
//#pragma warning(once:4005) // 在编译的时候，警告只出现1次
//#pragma warning(error:4005)  // 把c4005警告信息作为一个错误提示
//#pragma warning(default:4005) // 重置编译器的4005号警告行为到默认状态，由错误变成警告
//#pragma warning(push) // 把当前警告设置入栈
//#pragma warning(disable:4005) // 在编译的时候，屏蔽警告C4005
//#pragma warning(pop) // 把当前警告设置出栈，在一对push和pop之间作的任何报警相关设置都将失效
 
#define X 3
#define Y 4

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d, %d \n", X, Y);
#pragma push_macro("Y")     //宏Y入栈
	printf("%d, %d \n", X, Y);// 虽然宏Y入栈了，但还是Y=4


#define Y 6
#define X 7
	printf("%d, %d \n", X, Y);

#pragma pop_macro("Y") // Y出栈，覆盖了当前宏名称 [10/31/2018 hehuan]
	printf("%d, %d \n", X, Y); // 这里Y=4

	
	// pragma pack
//#pragma pack(1)
#pragma pack(2)

	typedef struct CreateData 
	{
		char szprintf;
		WORD wLength;
		DWORD dwSize;
		char szOutput;
	}tag_CreateData;

	tag_CreateData tagCreateData;
	memset(&tagCreateData, 0, sizeof(tagCreateData));
	DWORD dwSize1 = sizeof(tagCreateData);

	printf("%8x-%8x-%8x-%8x\n", &tagCreateData.szprintf,&tagCreateData.wLength,&tagCreateData.dwSize,&tagCreateData.szOutput);// 小写地址，8位但是0不显示
	printf("0x%08x-0x%08x-0x%08x-0x%08x\n", &tagCreateData.szprintf,&tagCreateData.wLength,&tagCreateData.dwSize,&tagCreateData.szOutput); // 小写地址，8位0也显示
	printf("0x%08X-0x%08X-0x%08X-0x%08X\n", &tagCreateData.szprintf,&tagCreateData.wLength,&tagCreateData.dwSize,&tagCreateData.szOutput); // 大写地址，8位0也显示
	system("pause");
	return 0;
}





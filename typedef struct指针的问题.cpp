// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>

typedef struct ANSWER_HEADER 
{
	int n1;
	int n2;
	unsigned char szNickName[34];
	struct ANSWER_HEADER* pNext;
	//PANSWER_HEADER_T pNext; // PANSWER_HEADER_T还没被定义，编译的时候报错。
}*PANSWER_HEADER_T, ANSWER_HEADER_T;

//typedef struct ANSWER_HEADER 
//{
//	int n1;
//	int n2;
//	unsigned char szNickName[34];
//	struct ANSWER_HEADER* pNext;
//	//PANSWER_HEADER_T pNext; // PANSWER_HEADER_T还没被定义，编译的时候报错。
//}ANSWER_HEADER_T, *PANSWER_HEADER_T;

//等同于如下
struct ANSWER_HEADER1
{
	int n1;
	int n2;
	unsigned char szNickName[10];
	struct ANSWER_HEADER1* pNext;
};
typedef struct ANSWER_HEADER1 ANSWER_HEADER_T1;
typedef struct ANSWER_HEADER1 *PANSWER_HEADER_T1;

// 其中PANSWER_HEADER_T为struct ANSWER_HEADER*的别名，其中PANSWER_HEADER_T为struct ANSWER_HEADER*的别名，PANSWER_HEADER_T为struct ANSWER_HEADER*的别名
// 重要的事说三遍。
// 另外，pNext必须定义为struct ANSWER_HEADER_T* pNext，如果定义为PANSWER_HEADER_T pNext就会报错，因为别名还没被编译，所以只能用结构体名来定义指向这个结构的指针。


int _tmain(int argc, _TCHAR* argv[])
{
	PANSWER_HEADER_T header = new ANSWER_HEADER_T;
	memset(header, 0, sizeof(ANSWER_HEADER_T));

	ANSWER_HEADER* header1 = new ANSWER_HEADER;
	memset(header1, 0, sizeof(ANSWER_HEADER));
	return 0;
}


// Test_pragma.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>


//#pragma warning(disable:4005;once:4005;error:4005) // һ�����Ĳ�����������������#pragma warning(disable:4005)��#pragma warning(once:4005)��#pragma warning(error:4005)
//#pragma warning(disable:4005) // �ڱ����ʱ�����ξ���C4005
//#pragma warning(once:4005) // �ڱ����ʱ�򣬾���ֻ����1��
//#pragma warning(error:4005)  // ��c4005������Ϣ��Ϊһ��������ʾ
//#pragma warning(default:4005) // ���ñ�������4005�ž�����Ϊ��Ĭ��״̬���ɴ����ɾ���
#pragma warning(push) // �ѵ�ǰ����������ջ
#pragma warning(disable:4005) // �ڱ����ʱ�����ξ���C4005
#pragma warning(pop) // �ѵ�ǰ�������ó�ջ����һ��push��pop֮�������κα���������ö���ʧЧ
 
#define X 3
#define Y 4

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d, %d \n", X, Y);
#pragma push_macro("Y")     //��Y��ջ
	printf("%d, %d \n", X, Y);// ��Ȼ��Y��ջ�ˣ�������Y=4


#define Y 6
#define X 7
	printf("%d, %d \n", X, Y);

#pragma pop_macro("Y") // Y��ջ�������˵�ǰ������ [10/31/2018 hehuan]
	printf("%d, %d \n", X, Y); // ����Y=4

	system("pause");
	return 0;
}





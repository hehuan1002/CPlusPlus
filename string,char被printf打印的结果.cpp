#include "stdafx.h"
#include "windows.h"
#include "string"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	std::string str = "heuan";

	// 打印乱码
	printf("%s\n", str);

	// 打印乱码
	printf("%s\n", &str);

	// 打印hehuan
	printf("%s\n", str.c_str());

	// 打印乱码
	printf("%c\n",&str);

	// 打印乱码
	printf("%c\n",str.c_str());

	// 打印首字母
	printf("%c\n",*str.c_str());

	// 打印hehuan
	std::cout<<str<<std::endl;

// printf为c函数，%s要求的是字符串首地址，而c里面并没有string这个东西。 [3/14/2019 hehuan]
	return 0;
}

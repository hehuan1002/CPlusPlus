// Test_copy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <Bitmap.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);

	std::vector<int> vec2;
	vec2.push_back(6);
	vec2.push_back(7);

	std::vector<int> vec3;
	vec3.reserve(vec1.size()+vec2.size());

	std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec3));
	std::vector<int>::iterator irr= vec3.begin()+2;
	//std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec3));
	std::copy(vec2.begin(), vec2.end(), (vec3.begin()+2));
	return 0;
}


// TestVector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
#include <vector> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);

	// û������vector����ĵ��ã����� [11/21/2018 hehuan]
	vector<int> v(vec1.begin(), vec1.end());  // �õ�����ȥ��ʼ��һ��vector�� ���캯��
	//template<class _Iter>
	//vector(_Iter _First, _Iter _Last)
	//	: _Mybase()
	//{	// construct from [_First, _Last)
	//	_Construct(_First, _Last, _Iter_cat(_First));
	//}

	vector<int> v2(100); // 100��
	//explicit vector(size_type _Count)
	//	: _Mybase()
	//{	// construct from _Count * _Ty()
	//	resize(_Count);
	//}

	vector<int> v3(100, 5); //100����ֵ��ʼ��Ϊ5
	//template<class _Iter>
	//void _Construct(_Iter _Count, _Iter _Val, _Int_iterator_tag)
	//{	// initialize with _Count * _Val
	//	size_type _Size = (size_type)_Count;
	//	_Ty _Newval = (_Ty)_Val;
	//	_Construct_n(_Size, _STD addressof(_Newval));
	//}
 
	cout << v.size() << endl; 
	v[200] = 1; 
	cout << v.size() << endl; 

	cout << v[199] << endl; 
	return 0;
}


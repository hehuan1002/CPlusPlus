
// TestTryCatch.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestTryCatchApp:
// �йش����ʵ�֣������ TestTryCatch.cpp
//

class CTestTryCatchApp : public CWinApp
{
public:
	CTestTryCatchApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestTryCatchApp theApp;
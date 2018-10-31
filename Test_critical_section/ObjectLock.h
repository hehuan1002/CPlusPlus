#pragma once
#include "AutoLock.h"

class CObjectLock
{
public:
	CObjectLock(CAutoLock *pLock):m_pLock(pLock) {m_pLock->Lock();}
	~CObjectLock(){m_pLock->UnLock();}

private:
	CAutoLock *m_pLock;
};


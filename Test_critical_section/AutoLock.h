#pragma once
#include <windows.h>

class CAutoLock
{
public:
	CAutoLock(){InitializeCriticalSection(&m_cs);}
	virtual ~CAutoLock() {DeleteCriticalSection(&m_cs);}

public:
	inline void Lock(){EnterCriticalSection(&m_cs);}
	inline void UnLock(){LeaveCriticalSection(&m_cs);}

private:
	CRITICAL_SECTION m_cs;
};


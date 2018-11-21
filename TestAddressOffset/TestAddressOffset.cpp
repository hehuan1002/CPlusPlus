// TestAddressOffset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>
using namespace std;

void Test1()
{
	typedef struct tagTkReqMsPushBetSeededPlayerResult
	{
		DWORD		dwBetID;
		DWORD		dwTeamID;	
		DWORD		dwPlayerCount;	
		DWORD		dwResultType;	
		DWORD		dwRank;		
		DWORD		dwScore;	
		DWORD		dwReserve1; 
		DWORD		dwReserve2; 
		// 后跟dwPlayerCount个dwUserID
	}TKREQMSPUSHBETSEEDEDPLAYERRESULT,*PTKREQMSPUSHBETSEEDEDPLAYERRESULT;


	DWORD sizeof1 = sizeof(TKREQMSPUSHBETSEEDEDPLAYERRESULT);
	DWORD sizeof2 = 2*sizeof(DWORD);

	char szPush[sizeof(TKREQMSPUSHBETSEEDEDPLAYERRESULT) + 2*sizeof(DWORD)];
	memset(szPush,0,sizeof(szPush));

	PTKREQMSPUSHBETSEEDEDPLAYERRESULT pReqPush = (PTKREQMSPUSHBETSEEDEDPLAYERRESULT)szPush;

	std::vector<DWORD> vecTestData;
	vecTestData.push_back(11);
	vecTestData.push_back(22);
	//vecTestData.push_back(33); 
	DWORD *pdwUID = (DWORD *)(pReqPush + 1); // 这里加1实际上地址偏移56个字节,换成(DWORD *)(pReqPush + 2)
	DWORD *pdwUID2 = (DWORD*)((char*)pReqPush + 56); // 地址偏移56个字节
	for ( std::vector< DWORD >::iterator it = vecTestData.begin(); it != vecTestData.end(); ++it )
	{
		*pdwUID = (*it);
		pdwUID++;// 偏移4个字节
		//pdwUID = pdwUID +1;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	return 0;
}


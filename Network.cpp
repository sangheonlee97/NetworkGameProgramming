#include "stdafx.h"
#include "Network.h"

DWORD WINAPI WaitFiveSecAndStart(LPVOID lpParam)
{
	WAITING_ROOM* ppNetInfo = (WAITING_ROOM*)lpParam;
	Sleep(5000);
	if (ppNetInfo->checkAllReady() == true) {
		ppNetInfo->sendStart();
	}
}

WAITING_ROOM::WAITING_ROOM()
{
	for (int i{}; i < 3; ++i) {
		player[i].nickname[0] = "\0";
		player[i].isReady = false;
		player[i].sock = NULL; // CreateThread() 실패한 경우도 NULL
		player[i].num = 0; // 0 - 플레이어 슬롯 비어있음

		sock[i] = (HANDLE)-1; // accept() 실패한 경우도 -1
	}

	listen = (HANDLE)-1; // listen() 실패한 경우도 -1
}

bool WAITING_ROOM::checkReduplication(char* name)
{
	for (int i{}; i < 3; ++i) {
		if (strcmp(player[i].nickname, name) == 0)
			return false;
	}
	return true;
}

void WAITING_ROOM::pressStart()
{
	if (this->checkAllReady() == true) {
		HANDLE hthr = CreateThread(NULL, 0, WaitFiveSecAndStart, NULL, 0, NULL);
		CloseHandle(hthr);
	}
}

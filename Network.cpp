#include "Network.h"

WAITING_ROOM::WAITING_ROOM()
{
	for (int i{}; i < 3; ++i) {
		player[i].nickname[0] = "\0";
		player[i].isReady = false;
		player[i].sock = NULL; // CreateThread() 실패한 경우도 NULL
		player[i].num = 0; // 0 - 플레이어 미식별
	}

	listen = (HANDLE)-1; // listen() 실패한 경우도 -1
}


#pragma once
#include "stdafx.h"
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();
	char* nickname; //플레이어 닉네임
	bool isReady; //플레이어 대기방 준비 여부
	SOCKET sock; //플레이어 소켓
	int num; //플레이어 식별번호
private:
};
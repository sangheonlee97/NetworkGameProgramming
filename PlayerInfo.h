#pragma once
#include "stdafx.h"
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();
	char* GetNick();
	void SetNick(char* name);
	bool GetIsReady();
	void SetIsReady(bool ready);
	SOCKET GetSock();
	void SetSock(SOCKET sock);
	int GetNum();
	void SetNum(int num); 
private:
	char* playerNickname; //플레이어 닉네임
	bool playerIsReady; //플레이어 대기방 준비 여부
	SOCKET playerSock; //플레이어 소켓
	int playerNum; //플레이어 식별번호
};
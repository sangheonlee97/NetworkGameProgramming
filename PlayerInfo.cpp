#include "stdafx.h"
#include "PlayerInfo.h"

PlayerInfo::PlayerInfo()
{
	
}

PlayerInfo::~PlayerInfo()
{
}

char* PlayerInfo::GetNick()
{
	return playerNickname;
}

void PlayerInfo::SetNick(char* name)
{
	strcpy(playerNickname, name);
}

bool PlayerInfo::GetIsReady()
{
	return playerIsReady;
}

void PlayerInfo::SetIsReady(bool ready)
{
	playerIsReady = ready;
}

SOCKET PlayerInfo::GetSock()
{
	return playerSock;
}

void PlayerInfo::SetSock(SOCKET sock)
{
	playerSock = sock;
}

int PlayerInfo::GetNum()
{
	return playerNum;
}

void PlayerInfo::SetNum(int num)
{
	playerNum = num;
}

#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"

enum class NetworkWaitInfo {
	NICKNAME,
	READY,
	REJECT,
	START
};

class WAITING_ROOM
{
public:
	WAITING_ROOM();
	~WAITING_ROOM(); //need msc
	bool checkReduplication(char* name);
	bool checkAllReady(); // need msc
	bool checkJoin(HANDLE handle); //ned ish
	void pressStart();
	void pressReady(int playerNumber); //need msc
	void receiveData(); //need ihr
	void refuseEnter(); //need msc
	void sendStart(); //need ish
	void stringAnalysis(char*); //need ihr
	
private:
	int playerCount; //대기방 안의 플레이어 수
	PlayerInfo player[3]; // need PayerInfo
	HANDLE listen;
	HANDLE sock[3]; // need to talk
};
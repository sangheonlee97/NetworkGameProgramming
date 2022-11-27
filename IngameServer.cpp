#include "stdafx.h"
#include "IngameServer.h"
#include "GameFrame.h"

void INGAME_SERVER::receivePress()
{
}

void INGAME_SERVER::inputManagement()
{
}

void INGAME_SERVER::objectInteract()
{
}

void INGAME_SERVER::sendState()
{
	/// <summary>
	/// [서버] 플레이어 정보, 오브젝트 정보를 송신하는 함수
	/// </summary>
	
}

void INGAME_SERVER::Render()
{
}

void INGAME_SERVER::sendEnd()
{
	/// <summary>
	/// 게임 종료 신호 송신
	/// </summary>
	int retval;
	for (int i = 0; i < playerCount; ++i)
	{
		retval = send(player[i].GetSock(), "END", sizeof("END"), 0);
		if (retval == SOCKET_ERROR) {
			printf("서버에서 게임종료신호 송신 오류");
			break;
		}
	}
	
}

void INGAME_SERVER::stringAnalysis(char*)
{

}

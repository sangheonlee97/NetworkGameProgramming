#include "stdafx.h"
#include "IngameClient.h"

void INGAME_CLIENT::sendPress()
{
}

void INGAME_CLIENT::receiveState()
{
}

void INGAME_CLIENT::Render()
{
}

void INGAME_CLIENT::receiveEnd()
{
	/// <summary>
	/// 게임 종료 명령어 받음
	/// </summary>
	//게임 종료 함수
}

void INGAME_CLIENT::stringAnalysis(char* command)
{
	//명령어 문자열 해석
	if (strcmp(command, "END") == 0)
	{
		receiveEnd();
	}
}

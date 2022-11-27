#include "stdafx.h"
#include "WaitingClient.h"

DWORD WINAPI roomClientReceiveThread(LPVOID lpParam)
{
	/// <summary>
	/// 클라이언트가 서버에서 오는 메시지 수신
	
	/// 게임시작 신호, 다른 유저의 입장,레디나 체디취소 등 수신
	/// 고정길이 + 가변길이
	/// </summary>
	/// <returns></returns>
	WATING_CLIENT WC;
	int retval; //받기 리턴 값
	char rcrBuf[2048]; //고정길이
	int rcrLen; // 고정 길이 데이터
	while (1)
	{
		//고정길이 받기
		retval = recv(WC.serverSock, (char*)&rcrLen, sizeof(int), 0);
		if (retval == SOCKET_ERROR) {
			// 실패시 게임 종료
			return 0;
		}
		else if (retval == 0)
			break;

		//가변 데이터 받기
		retval = recv(WC.serverSock, rcrBuf, rcrLen, MSG_WAITALL);
		if (retval == SOCKET_ERROR) {
			// 실패시 게임종료
			return 0;
		}
		else if (retval == 0)
			break;
		
		WC.stringAnalysis(rcrBuf);
	}
}
DWORD WINAPI roomClientSendThread(LPVOID lpParam)
{
	/// <summary>
	/// 클라이언트에서 서버에게 메시지 송신하는 쓰레드
	/// 입장, 레디, 레디취소 송신 
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>
	int retval; //보내기 리턴 값
}
void WATING_CLIENT::sendReady()
{
}
void WATING_CLIENT::receiveReady(int playerNumber)
{
	/// <summary>
	/// 클라이언트가 ready 
	/// ready 버튼 누를 때마다 isReady에 true, false값 전환
	/// </summary>
	/// <param name="playerNumber">플레이어 식별번호</param>
	player[playerNumber].SetIsReady(player[playerNumber].GetIsReady() ? false : true); //true면 false, false면 true 변환.
}

void WATING_CLIENT::receiveStart()
{
}

void WATING_CLIENT::stringAnalysis(char* command)
{
	if (strcmp(command, "ST") == 0)
	{
		//ST: 게임시작 신호
		//게임시작
	}
	else if (strcmp(command, "ST") == 0)
	{
		//RJ: 대기방 입장 거절 신호
		//대기방 나가기
	}
	else if (strncmp(command, "RD", 2) == 0)
	{
		//RD: 레디 신호
		receiveReady(command[2]);
	}
}

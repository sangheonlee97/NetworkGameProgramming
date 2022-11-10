#include "framework.h"

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
	~WAITING_ROOM(); //need
	
	bool checkReduplication(char* name);
	bool checkAllReady(); // need msc
	bool checkJoin(HANDLE); //ned ish
	void pressStart();
	void pressReady(int playerNumber); //need msc
	void sendStart(); // need ish
	void receiveData(); //need ihr
	void refuseEnter(); //need msc
	void sendStart(); //need ish
	void stringAnalysis(char*); //need ihr
	
private:
	int PlayerCount; //플레이어 총 몇명인지
	PlayerInfo player[3]; // need PayerInfo
	HANDLE listen;
	HANDLE sock[3]; // need to talk
};
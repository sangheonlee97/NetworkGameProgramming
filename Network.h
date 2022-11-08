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
	bool checkReduplication(char* name);
	bool checkAllReady(); // need checkAllReady
	void pressStart();
	void sendStart(); // need sendStart
	
private:
	PlayerInfo player[3]; // need PayerInfo
	HANDLE listen;
	HANDLE sock[3]; // need to talk
};
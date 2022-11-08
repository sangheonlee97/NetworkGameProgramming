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

private:
	PlayerInfo player[3]; // need PayerInfo
	HANDLE listen;

};
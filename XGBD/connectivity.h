#pragma once
#include "framework.h"
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

enum CONN_TYPE {
	PIZZA_BOY, BGB, XGBD
};

struct connection {
	CONN_TYPE conn_type;
	BOOL server;
	SOCKET socket;
};

HRESULT connect();
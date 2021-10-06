#pragma once

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>


#pragma comment(lib,"ws2_32.lib")

unsigned getip(char* doma, char* ipaddr);

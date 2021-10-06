#pragma once


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#pragma comment(lib, "WS2_32")    

#define DEF_PACKET_SIZE 32
#define ECHO_REQUEST 8
#define ECHO_REPLY 0

struct IPHeader
{
    BYTE m_byVerHLen;
    BYTE m_byTOS;
    USHORT m_usTotalLen;
    USHORT m_usID;
    USHORT m_usFlagFragOffset;
    BYTE m_byTTL; //TTL
    BYTE m_byProtocol;
    USHORT m_usHChecksum;
    ULONG m_ulSrcIP;
    ULONG m_ulDestIP;
};

struct ICMPHeader
{
    BYTE m_byType;
    BYTE m_byCode; //
    USHORT m_usChecksum;
    USHORT m_usID;
    USHORT m_usSeq;
    ULONG m_ulTimeStamp;
};

struct PingReply
{
    USHORT m_usSeq;
    DWORD m_dwRoundTripTime;
    DWORD m_dwBytes;
    DWORD m_dwTTL;
};

class CPing
{
public:
    CPing();
    ~CPing();
    BOOL Ping(DWORD dwDestIP, PingReply* pPingReply = NULL, DWORD dwTimeout = 2000);
    BOOL Ping(char* szDestIP, PingReply* pPingReply = NULL, DWORD dwTimeout = 2000);
private:
    BOOL PingCore(DWORD dwDestIP, PingReply* pPingReply, DWORD dwTimeout);
    USHORT CalCheckSum(USHORT* pBuffer, int nSize);
    ULONG GetTickCountCalibrate();
private:
    SOCKET m_sockRaw;
    WSAEVENT m_event;
    USHORT m_usCurrentProcID;
    char* m_szICMPData;
    BOOL m_bIsInitSucc;
private:
    static USHORT s_usPacketSeq;
};

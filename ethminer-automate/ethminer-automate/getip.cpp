#include "getip.h"



unsigned getip(char* doma, char* ipaddr) {

	WSADATA getip;
	WSAStartup(MAKEWORD(2, 2), &getip);


	struct addrinfo destip;
	struct addrinfo* res, * cur;
	struct sockaddr_in* addr;
	// store ip xxx.xxx.xxx.xxx
	//char m_IpAddr[16];

	//
	memset(&destip, 0, sizeof(addrinfo));
	destip.ai_family = AF_INET;	//IPv4
	destip.ai_flags = AI_PASSIVE; //
	destip.ai_protocol = 0;        //
	destip.ai_socktype = SOCK_STREAM; //

	//
	int ret = getaddrinfo(doma, NULL, &destip, &res);
	if (ret == -1)
	{
		perror("getaddrinfo");
		exit(-1);
	}

	//
	for (cur = res; cur != NULL; cur = cur->ai_next)
	{
		addr = (struct sockaddr_in*)cur->ai_addr; //

		sprintf(ipaddr, "%d.%d.%d.%d", addr->sin_addr.S_un.S_un_b.s_b1,
			addr->sin_addr.S_un.S_un_b.s_b2,
			addr->sin_addr.S_un.S_un_b.s_b3,
			addr->sin_addr.S_un.S_un_b.s_b4);

		//printf("%s\n", m_IpAddr); //
	}
	//
	WSACleanup();
	//system("pause");
	return 0;




}
/*
#include <winsock2.h>
#include <iostream>
#include <WS2tcpip.h>
#include "StdAfx.h"

int main()
{
	SOCKET serverSocket, acceptSocket;

	int port = 54321;

	WSADATA wsaData;
	int wsaErr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaErr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaErr != 0)
	{
		std::cout << "Winsock DLL not found!" << std::endl;
		return 0;
	}

	std::cout << "Status: " << wsaData.szSystemStatus << std::endl;



	sockaddr_in service;
	service.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);

	if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
	{
		std::cout << "Socket binding failed :( " << WSAGetLastError() << std::endl;
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}

	std::cout << "Server socket bound..." << std::endl;

	if (listen(serverSocket, 1) == SOCKET_ERROR)
	{
		std::cout << "Error while trying to listen! " << WSAGetLastError() << std::endl;
		return 0;
	}

	std::cout << "Server listening on port 54321" << std::endl;

	acceptSocket = accept(serverSocket, NULL, NULL);

	if (acceptSocket == INVALID_SOCKET)
	{
		std::cout << "Accept failed! " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;
	}

	std::cout << "Accepted connection..." << std::endl;

	char message[13];
	int bytesRecieved = recv(acceptSocket, (char*)&message, 13, 0);
	if (bytesRecieved == SOCKET_ERROR)
	{
		std::cout << "Couldn't recieve message :( " << WSAGetLastError() << std::endl;
		std::cin.get();
		return 0;
	}

	std::cout << "[Client]: " << message << std::endl;

	WSACleanup();

	std::cin.get();
}

*/

#include "Socket.h"
#include <iostream>

int main() {

	WSADATA wsaData;
	int wsaErr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaErr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaErr != 0)
	{
		std::cout << "Winsock DLL not found!" << std::endl;
		return 0;
	}

	auto socket = Tayl::Socket::CreateSocket();
	socket->bind_to("127.0.0.1", 54321);

}































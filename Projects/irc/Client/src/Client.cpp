#include <iostream>
#include <winsock2.h>
#include "StdAfx.h"
#include <WS2tcpip.h>

int main() {
	SOCKET clientSocket, acceptSocket;

	int port = 54321;

	WSADATA wsaData;
	int wsaErr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaErr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaErr != 0)
	{
		std::cout << "Winwock DLL not found!" << std::endl;
		return 0;
	}

	std::cout << "Status: " << wsaData.szSystemStatus << std::endl;

	clientSocket = INVALID_SOCKET;

	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSocket == INVALID_SOCKET)
	{
		std::cout << "Error creating server socket" << WSAGetLastError() << std::endl;
		WSACleanup();
		return 0;
	}

	std::cout << "Server socket created..." << std::endl;

	sockaddr_in service;
	service.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);

	if (connect(clientSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
	{
		std::cout << "Failed to connect :( " << WSAGetLastError() << std::endl;
		closesocket(clientSocket);
		WSACleanup();
		return 0;
	}

	std::cout << "Connected to server socket..." << std::endl;
	std::cout << "Waiting for data..." << std::endl;

	char message[] = "Hey! -Client";
	int bytesSent = send(clientSocket, message, 13, 0);

	if (bytesSent == SOCKET_ERROR)
	{
		std::cout << "Couldn't send bytes :( " << WSAGetLastError() << std::endl;
		return 0;
	}

	std::cout << "Sent: " << bytesSent << " bytes" << std::endl;

	WSACleanup();

	std::cin.get();
}

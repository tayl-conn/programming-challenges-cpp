#include "Socket.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "StdaFx.h"
#include <Windows.h>
#include <memory>

namespace Tayl
{

	Socket::Socket(TransferType transferType, WindowsSocket socket)
		: transferType(transferType), m_Socket(socket)
	{

	}

	std::unique_ptr<Socket> Socket::CreateSocket(TransferType transferType)
	{
		WindowsSocket createdSocket = INVALID_SOCKET;
		createdSocket = socket(AF_INET, SOCK_STREAM, transferType);

		if (createdSocket == INVALID_SOCKET)
		{
			std::cout << "[Error]: Couldn't create socket - " << WSAGetLastError() << std::endl;
			return nullptr;
		}

		return std::make_unique<Socket>(Socket(transferType, createdSocket));
	}

	void Socket::bind_to(std::string address, int port)
	{
		sockaddr_in service;
		service.sin_family = AF_INET;

		std::wstring addrTemp = std::wstring(address.begin(), address.end());
		LPCWSTR addrPwstr = addrTemp.c_str();

		InetPton(AF_INET, addrPwstr, &service.sin_addr.s_addr);
		service.sin_port = htons(port);

		if (bind(m_Socket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
		{
			std::cout << "Socket binding failed - " << WSAGetLastError() << std::endl;
			return;
		}
	}

	int sendData(WindowsSocket socket, char* bufferToRead, int lengthOfBufferInBytes)
	{
		return 0;
	}

	int recieveData(WindowsSocket socket, char* bufferToWrite, int lengthOfBufferInBytes)
	{
		return 0;
	}

	void connect(WindowsSocket socketToConnect) {

	}

}
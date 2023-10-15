#include <string>
#include <winsock2.h>
#include <memory>
#include <iostream>

namespace Tayl
{
	typedef SOCKET WindowsSocket;
	typedef PCWSTR PTR_TO_WIDE_STR;

	enum TransferType
	{
		TCP = IPPROTO_TCP,
		UDP = IPPROTO_UDP
	};

	enum SocketError
	{
		NO_ERR,
		WSA_NOT_INIT = 10093
	};

	class Socket
	{

	public:

		static std::unique_ptr<Socket> CreateSocket(TransferType transferType = TCP);

		int sendData(WindowsSocket socket, char* bufferToRead, int lengthOfBufferInBytes);

		int recieveData(WindowsSocket socket, char* bufferToWrite, int lengthOfRecievedBufferInBytes);

		void connect(WindowsSocket socketToConnect);

		void bind_to(std::string address, int port);

	private:

		Socket(TransferType transferType, WindowsSocket socket);

		int port;
		std::string address;
		TransferType transferType;
		WindowsSocket m_Socket;

	};


}
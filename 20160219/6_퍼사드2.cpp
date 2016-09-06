// 6_퍼사드

#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment( lib, "ws2_32.lib")

class NetAddress
{
	SOCKADDR_IN addr;
public:
	NetAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}

	SOCKADDR* getRawAddress() { return (SOCKADDR*)&addr; }
};

class NetworkSystem
{
public:
	NetworkSystem()
	{
		// 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}

	~NetworkSystem()
	{
		WSACleanup();
	}
};

class Socket
{
	int sock;
public:
	Socket(int type)
	{ sock = socket(PF_INET, type, 0); }

	void bind(NetAddress* addr)
	{
		::bind(sock, addr->getRawAddress(), sizeof(SOCKADDR_IN));
	}

	void listen(int backlog) { ::listen(sock, 5); }
	void accept()
	{
		SOCKADDR_IN addr2 = { 0 };
		int sz = sizeof(addr2);
		::accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP 서버 프로그램을 하는데 필요한 클래스와 절차를
// 단순화 시켜주는 상위 개념의 클래스를 제공하자 => Facade Pattern
// C++ Network Programming - 더글라스 슈미트
// http://d.pr/n/11LeB
class TCPServer
{
	NetworkSystem system;
	Socket socket;
public:
	TCPServer() : socket(SOCK_STREAM) {}

	void start(const char* s, short port)
	{
		NetAddress address(s, port);
		socket.bind(&address);
		socket.listen(5);
		socket.accept();
	}
};

int main()
{
	TCPServer server;
	server.start("127.0.0.1", 5000);
}



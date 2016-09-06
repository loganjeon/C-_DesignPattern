// 6_�ۻ��

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
		// ��Ʈ��ũ ���̺귯�� �ʱ�ȭ
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

// TCP ���� ���α׷��� �ϴµ� �ʿ��� Ŭ������ ������
// �ܼ�ȭ �����ִ� ���� ������ Ŭ������ �������� => Facade Pattern
// C++ Network Programming - ���۶� ����Ʈ
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



// 6_�ۻ��

#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment( lib, "ws2_32.lib")

// http://d.pr/n/12To7
int main()
{
	WSADATA w;
	WSAStartup(0x202, &w); // ��Ʈ��ũ ���̺귯�� �ʱ�ȭ

	// 1. ���� ����
	int sock = socket(PF_INET, SOCK_STREAM, 0); // TCP ����

	// 2. ���Ͽ� �ּ� ����
	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	// 3. ������ ��� ���·κ���
	listen(sock, 5);

	// 4. Ŭ���̾�Ʈ ���
	SOCKADDR_IN addr2 = { 0 };
	int sz = sizeof(addr2);

	accept(sock, (SOCKADDR*)&addr2, &sz);// Client�� ������
										 // �� ���� ����Ѵ�.

	WSACleanup();
}



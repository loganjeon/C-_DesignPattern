#include <string>
#include <iostream>
using namespace std;

// http://d.pr/n/1cADc
// 5_����
// : ������ ��������� ��������� �� ������ ǥ���� �޶����� ��ü�� ���� ��
struct IBuilder
{
	virtual void makeUniform() = 0;
	virtual void makeHat() = 0;
	virtual void makeShoes() = 0;

	virtual string getResult() = 0;

	virtual ~IBuilder() {}
}; 


// �౸ ������ ĳ���͸� ����� ������ ������ �ʽ��ϴ�.
class Director
{
	IBuilder* pBuilder;
public:
	void setBuilder(IBuilder* p) { pBuilder = p; }

	string construct() 
	{
		pBuilder->makeUniform();
		// pBuilder->makeHat();
		pBuilder->makeShoes();
	
		return pBuilder->getResult();
	}
};


// �پ��� ���� �Ǵ� ���� ������ �����մϴ�.
class Korean : public IBuilder
{
	string s;
public:
	void makeHat() { s += "��"; }
	void makeUniform() { s += "�Ѻ�"; }
	void makeShoes() { s += "¤��"; }

	string getResult() { return s; }
};

class American : public IBuilder
{
	string s;
public:
	void makeHat() { s += "�߱�����"; }
	void makeUniform() { s += "�纹"; }
	void makeShoes() { s += "����"; }

	string getResult() { return s; }
};

int main()
{
	Korean k; American a;

	Director d;
	d.setBuilder(&a);   // ĳ���� ���� ȭ��ǥŰ�� ������ ����Ǵ� �ڵ�
	cout << d.construct() << endl;
}
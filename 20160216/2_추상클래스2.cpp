#include <iostream>
using namespace std;

// 2_�߻�Ŭ����2
// ���յ� : 'Ŭ���� ���� ���� �ٸ� å�ӵ��� ���� �ִ� ��ȣ ������ ����'

// 1. ī�޶� ����ڿ� ī�޶� ������ ������ ��Ģ�� ���� �����Ѵ�.
//   (�������̽�, ��༭, ��������)

struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}
	// �������̽��� �ᱹ �θ��̴�. ���� �Ҹ��ڰ� �ʿ��ϴ�.
};

// 2. ��¥ ī�޶�� ������, ��Ģ�� �ִ�. ��Ģ��θ� ����ϸ� �ȴ�.
class Person
{
public:
	void takePicture(ICamera* p) { p->take(); }
};

// 3. "��� ī�޶�� ���� Ŭ������ ���� ��ӹ޾ƾ� �Ѵ�." ��� ���� ����
//    "��� ī�޶�� ���� �������̽��� �����ؾ� �Ѵ�."
class Camera : public ICamera
{
public:
	virtual void take() {
		cout << "take picture with Camera" << endl;
	}
};

// �ٽ� : ��ü �����Ϸ��� �������̽��� �ʿ��ϴ�.
// DIP(Dependency Inversion Principle) : �������� ���� ��Ģ
// Ŭ���̾�Ʈ�� ��ü Ŭ������ �����ϴ� ���� �ƴ϶� �������̽��� �߻� Ŭ������ �����ؾ�
// �Ѵٴ� ��Ģ.

// http://d.pr/n/1clhH
// ���� ����(loosely coupling) : �ϳ��� Ŭ������ �ٸ� Ŭ������ ����� ��
//                               �θ��� �߻� Ŭ������ ����ؼ� �����ϴ� ��.
// "��ü ������ ������ ������" => OCP �� �����Ѵ�.

class SmartPhone : public ICamera
{
public:
	virtual void take() {

	}
};



int main()
{
	Person p;
	Camera c;
	SmartPhone sp;

	p.takePicture(&sp);
}






#if 0
class Camera
{
public:
	void take() { cout << "take picture with Camera" << endl; }
};

class SmartPhone
{
public:
	void take() { cout << "take picture with SmartPhone" << endl; }
};


class Person
{
public:
	void takePicture(Camera* p) { p->take(); }
};

int main()
{
	Person p;
	Camera c;

	p.takePicture(&c);
}
#endif
// 8_�긴��
#include <iostream>
using namespace std;

// http://d.pr/n/1cHaA
// C++ pimpl idiom �̶�� �̸����ε� �˷��� �ֽ��ϴ�.
// => ������ �ӵ��� ������ �� �� �ִ� ������ �ִ�. "�����Ϸ� ��ȭ��"

// ������ �߰��� �̿��� ������ ����!!!
class MP3 : public IMP3
{
public:
	void play() { cout << "play music with MP3" << endl; }
	void stop() { cout << "stop music" << endl; }
};

class iPod : public IMP3
{
public:
	void play() { cout << "play music with iPOD" << endl; }
	void stop() { cout << "stop music" << endl; }
};

// �����ο� �������̽��� �и��ؼ� ��ȣ �������� ������ �����ϵ��� �ؾ� �Ѵ�.
struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;

	virtual ~IMP3() {}
};

class MP3Bridge
{
	IMP3* pImpl;
public:
	MP3Bridge(IMP3* p = 0) : pImpl(p)
	{
		if (pImpl == 0)
			pImpl = new MP3();
	}

	void play() { pImpl->play(); }
	void stop() { pImpl->stop(); }

	void playOneMinute()
	{
		play();
		//...
		stop();
	}

};


// ����ڰ� ������(IMP3) �� ���� ������� ����, �߰����� ��������.
class Person
{
public:
	void useMP3(MP3Bridge* p) { p->playOneMinute(); }
};



int main()
{
	Person person; MP3 mp3; iPod pod;
	person.useMP3(&pod);
}
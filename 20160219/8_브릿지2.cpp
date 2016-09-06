// 8_브릿지
#include <iostream>
using namespace std;

// http://d.pr/n/1cHaA
// C++ pimpl idiom 이라는 이름으로도 알려져 있습니다.
// => 컴파일 속도를 빠르게 할 수 있는 장점이 있다. "컴파일러 방화벽"

// 계층의 추가를 이용한 유연성 증대!!!
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

// 구현부와 인터페이스를 분리해서 상호 독립적인 변경이 가능하도록 해야 한다.
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


// 사용자가 구현부(IMP3) 를 직접 사용하지 말고, 중간층을 도입하자.
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
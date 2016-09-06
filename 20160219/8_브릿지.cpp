
// 8_ºê¸´Áö

#include <iostream>
using namespace std;

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;

	virtual ~IMP3() {}
};

// http://d.pr/n/113Nm
class Person
{
public:
	void useMP3(IMP3* p) { p->playOneMinute(); }
};

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


int main()
{
	Person person; MP3 mp3; iPod pod;
	person.useMP3(&pod);
}
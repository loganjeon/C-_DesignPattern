#include <iostream>
#include <string>
#include <Windows.h>  // Sleep(ms) 
                      // #include <unistd.h> - sleep(sec), usleep()
using namespace std;

// 8_플라이웨이트
// 속성이 동일한 객체가 다수 생성된다면, 하나의 객체를 공유해서 사용하자.

class Image
{
	string url;
public:
	Image(string s) : url(s) {
		cout << "Loading from " << url << endl;
		
		Sleep(3000);
	}

	void draw() { cout << "Draw Image " << url << endl; }
};

// http://d.pr/n/1gdgH
int main()
{
	Image* img1 = new Image("http://www.a.com/a.png");
	img1->draw();

	Image* img2 = new Image("http://www.a.com/a.png");
	img2->draw();
}


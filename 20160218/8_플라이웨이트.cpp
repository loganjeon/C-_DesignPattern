#include <iostream>
#include <string>
#include <Windows.h>  // Sleep(ms) 
                      // #include <unistd.h> - sleep(sec), usleep()
using namespace std;

// 8_�ö��̿���Ʈ
// �Ӽ��� ������ ��ü�� �ټ� �����ȴٸ�, �ϳ��� ��ü�� �����ؼ� �������.

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


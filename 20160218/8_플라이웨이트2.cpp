// 8_플라이웨이트2
#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

// 속성이 동일한 객체가 다수 생성된다면, 하나의 객체를 공유해서 사용하자.

class Image
{
	string url;
	
	Image(string s) : url(s) {
		cout << "Loading from " << url << endl;
		Sleep(3000);
	}
public:
	void draw() { cout << "Draw Image " << url << endl; }
	
	friend class ImageFactory;
};

#include <map>

// http://d.pr/n/wT1H
// 공장(Factory) : 객체를 생성하는 역활을 수행하는 클래스
//                 일반적으로 싱글톤으로 만드는 경우가 많습니다.
// 장점 : 객체의 생성 방법을 한곳에서 중앙 집중적으로 관리할 수 있다.
class ImageFactory
{
	map<string, Image*> image_map;

	ImageFactory() {}
	ImageFactory(const ImageFactory&);
	void operator=(ImageFactory&);
public:
	static ImageFactory& get()
	{
		static ImageFactory factory;
		return factory;
	}

	Image* createImage(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}
};


int main()
{
	ImageFactory& factory = ImageFactory::get();

	Image* img1 = factory.createImage("http://www.a.com/a.png");
	img1->draw();

	Image* img2 = factory.createImage("http://www.a.com/a.png");
	img2->draw();
}


// 8_�ö��̿���Ʈ2
#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

// �Ӽ��� ������ ��ü�� �ټ� �����ȴٸ�, �ϳ��� ��ü�� �����ؼ� �������.

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
// ����(Factory) : ��ü�� �����ϴ� ��Ȱ�� �����ϴ� Ŭ����
//                 �Ϲ������� �̱������� ����� ��찡 �����ϴ�.
// ���� : ��ü�� ���� ����� �Ѱ����� �߾� ���������� ������ �� �ִ�.
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


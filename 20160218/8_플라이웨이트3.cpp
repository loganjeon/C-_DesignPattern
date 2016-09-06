// 8_�ö��̿���Ʈ3
#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

#include <map>

// �ö��̿���Ʈ ���� ����!!!
// : �ö��̿���Ʈ ������ �����ϱ� ���ؼ��� ��ü�� �Һ� ��ü, �� ������ �Ұ����ϰ� 
//   ������ �Ѵ�.

class Image
{
	string url;
	
	Image(string s) : url(s) {
		cout << "Loading from " << url << endl;

		Sleep(3000);
	}

	static map<string, Image*> image_map;
public:
	// ���� ���丮 �޼ҵ�(static factory method) : Java
	// ���� ������ : ObjC
	// 1) �����ں��� �������� ����.
	// 2) ������ó�� �����ε��� �Ѱ谡 ����.
	// 3) ��ü�� �����ϴ� ����� ������ ������ϴ�.
	static Image* imageWithURL(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}

	void draw() { cout << "Draw Image " << url << endl; }
};

// http://d.pr/n/jXxA
map<string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::imageWithURL("http://www.a.com/a.png");
	img1->draw();

	Image* img2 = Image::imageWithURL("http://www.a.com/a.png");
	img2->draw();
}


#if 0
ArrayList<Integer> datas = new ArrayList<>();
for (int i = 0; i < 100; ++i) {
	datas.add(i); // Integer : auto boxing
	              // datas.add(Integer.valueOf(i));
}
#endif
// 8_플라이웨이트3
#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;

#include <map>

// 플라이웨이트 주의 할점!!!
// : 플라이웨이트 패턴을 적용하기 위해서는 객체를 불변 객체, 즉 수정이 불가능하게 
//   만들어야 한다.

class Image
{
	string url;
	
	Image(string s) : url(s) {
		cout << "Loading from " << url << endl;

		Sleep(3000);
	}

	static map<string, Image*> image_map;
public:
	// 정적 팩토리 메소드(static factory method) : Java
	// 편의 생성자 : ObjC
	// 1) 생성자보다 가독성이 좋다.
	// 2) 생성자처럼 오버로딩에 한계가 없다.
	// 3) 객체를 생성하는 방법을 마음껏 제어가능하다.
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
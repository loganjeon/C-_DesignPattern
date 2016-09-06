// 9_�߻����丮
#include <iostream>
using namespace std;
// Qt���� �����ϴ� GUI Look&Feel ����� �����غ��ô�.

// �߻� ���丮 ������ �ǵ��� ���嵵 �������̽� ������� �����ؼ�
// ��ü �����ϵ��� ����.

// program.exe --style=GTK
//             --style=XP
struct IButton { virtual void draw() = 0; };
struct IEdit { virtual void draw() = 0; };

struct GTKButton : IButton { 
	void draw() { cout << "GTKButton draw" << endl; } 
};
struct XPButton : IButton {
	void draw() { cout << "XPButton draw" << endl; }
};

struct GTKEdit : IEdit {
	void draw() { cout << "GTKEdit draw" << endl; }
};

struct XPEdit : IEdit {
	void draw() { cout << "XPEdit draw" << endl; }
};

struct IFactory {
	virtual IButton* createButton() = 0;
	virtual IEdit*   createEdit() = 0;
};


// ��Ÿ�Ͽ� ���� ��Ʈ���� ����� ������ �����.
class XPFactory : public IFactory
{
public:
	IButton* createButton() { return new XPButton; }
	IEdit*   createEdit() { return new XPEdit; }
};

class GTKFactory : public IFactory
{
public:
	IButton* createButton() { return new GTKButton; }
	IEdit*   createEdit() { return new GTKEdit; }
};

// http://d.pr/n/10IGL
int main(int argc, char* argv[])
{
	IFactory* factory;

	if (strcmp(argv[1], "GTK") == 0) {
		factory = new GTKFactory;
	}
	else {
		factory = new XPFactory;
	}

	IButton* p1 = factory->createButton();
	IEdit* p2 = factory->createEdit();

	p1->draw();
	p2->draw();

}



#if 0

int main(int argc, char* argv[])
{
	IButton* button;
	IEdit*   edit;
	if (strcmp(argv[1], "GTK") == 0) {
		button = new GTKButton;
		edit = new GTKEdit;
		//......
	} else {
		button = new XPButton;
		edit = new XPEdit;
		//......
	}

	//.......
	button->draw();
}
#endif
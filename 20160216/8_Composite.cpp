#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item
{
	string name;
public:
	Item(string s) : name(s) {}
	virtual ~Item() {}

	virtual int getSize() = 0;
};

class File : public Item
{
	int size;
public:
	File(string s, int n) : Item(s), size(n) {}

	int getSize() { return size; }
};

// http://d.pr/n/1gHlJ
// ���� ��ü�� �ڽ��� ������ �ִ� ��ü�� ���� �޸� ���� å�ӵ�
// �����Ѵ�.
class Folder : public Item
{
	vector<Item*> v;
public:
	Folder(string s) : Item(s) {}
	~Folder() {
		for (int i = 0; i < v.size(); ++i) {
			delete v[i];
		}
	}

	void addItem(Item* p) { v.push_back(p); }

	int getSize() 
	{
		int size = 0;
		for (int i = 0; i < v.size(); ++i) {
			size += v[i]->getSize();
		}
		return size;
	}
};



int main()
{
	// �Ʒ��ڵ尡 ����ǵ��� Folder, File Ŭ������ ����� ������
	Folder* fol1 = new Folder("ROOT");
	Folder* fol2 = new Folder("A");

	File* f1 = new File("a.txt", 10); // �̸�, ũ��
	File* f2 = new File("b.txt", 20);

	// ���輳��
	fol2->addItem(f1);
	fol1->addItem(f2);
	fol1->addItem(fol2);
	cout << f2->getSize() << endl;
	cout << fol2->getSize() << endl;
	cout << fol1->getSize() << endl;

	delete fol1;
}
// 3_LineEdit2
#include <string>
#include <iostream>
using namespace std;

#include <conio.h>  // getch

// LineEdit�� validation ��å�� ����Ǿ�� �Ѵ�.

// ���뼺�� �������� �и� 
// ��� 1. ���ϴ� ���� �����Լ�ȭ �Ѵ�. - Template Method
//  : ������ �ʴ� �ڵ�(���뼺)���� ���ؾ� �ϴ� ��(������)�� �ִٸ�
//    ���ؾ� �ϴ� ���� �����Լ��� �и��Ѵ�.

// http://d.pr/n/1aSi0
// �Ѱ���
// 1. ���� �ð��� ��å�� �����ϴ� ���� �Ұ����ϴ�.
// 2. �ٸ� Ŭ�������� ��å�� �����ϴ� ���� �Ұ����ϴ�.

class LineEdit
{
	string data;
public:
	virtual bool validate(char c) { return isdigit(c); }

	string getData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13) break;  // enter

			if (validate(c))
			{
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

// ���� ��å�� �����ϰ� �ʹٸ�, �Ļ� Ŭ�������� �����Լ��� �������ϸ� �ȴ�.
class AddressEdit : public LineEdit
{
public:
	virtual bool validate(char c) { return true; }
};

int main()
{
	AddressEdit edit;
	while (1)
	{
		string s = edit.getData();
		cout << "input : " << s << endl;
	}
}
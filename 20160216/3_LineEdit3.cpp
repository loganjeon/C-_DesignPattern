// 3_LineEdit3
#include <string>
#include <iostream>
using namespace std;

#include <conio.h>  // getch

// ���뼺�� �������� �и�
// ��� 2. ���ϴ� ���� �ٸ� Ŭ������ �и��Ѵ�. => ���� �� �־�� �ϹǷ� ��ü �����ؾ� �Ѵ�.
//                                                : �������̽��� �ʿ��ϴ�!
// ���� ���� : Strategy Pattern

// 1. ����ð��� ��å�� �����ϴ� ���� �����ϴ�.
// 2. ��å�� �ٸ� Ŭ�������� ���� �����ϴ�.

// Qt���� QValidator��� �������̽��� �ֽ��ϴ�.
// http://d.pr/n/1emNQ
struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool isComplete(string s) = 0;

	virtual ~IValidator() {}
};

class LineEdit
{
	string data;

	//-------------------
	IValidator* pValidator;
public:
	LineEdit() : pValidator(0) {}
	void setValidator(IValidator* p) { pValidator = p; }
	//-------------------

	string getData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13 &&
				(pValidator == 0 || pValidator->isComplete(data) ) ) 
				break;  // enter

			if (pValidator == 0 || pValidator->validate(data, c) )
			{
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

// http://d.pr/n/6ciP
// ���� �پ��� Validator�� �����ϸ� �˴ϴ�.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(string s, char c)
	{
		return s.size() < value && isdigit(c);
	}

	virtual bool isComplete(string s)
	{
		return s.size() == value;
	}
};

int main()
{
	LineEdit edit;

	LimitDigitValidator v(5);
	edit.setValidator(&v);

	while (1)
	{
		string s = edit.getData();
		cout << "input : " << s << endl;
	}
}
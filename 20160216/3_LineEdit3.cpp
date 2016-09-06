// 3_LineEdit3
#include <string>
#include <iostream>
using namespace std;

#include <conio.h>  // getch

// 공통성과 가변성의 분리
// 방법 2. 변하는 것을 다른 클래스로 분리한다. => 변할 수 있어야 하므로 교체 가능해야 한다.
//                                                : 인터페이스가 필요하다!
// 전략 패턴 : Strategy Pattern

// 1. 실행시간에 정책을 변경하는 것이 가능하다.
// 2. 정책을 다른 클래스에서 재사용 가능하다.

// Qt에는 QValidator라는 인터페이스가 있습니다.
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
// 이제 다양한 Validator를 제공하면 됩니다.
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
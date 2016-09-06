// 3_LineEdit.cpp

#include <string>
#include <iostream>
using namespace std;

#include <conio.h>  // getch

// http://d.pr/n/1lg6K
// GUI도구인 EditBox를 만들어 봅시다.
class LineEdit
{
	string data;
public:
	string getData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13) break;  // enter

			if (isdigit(c))
			{
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

int main()
{
	LineEdit edit;
	while (1)
	{
		string s = edit.getData();
		cout << "input : " << s << endl;
	}
}
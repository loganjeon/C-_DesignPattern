#include <string>
#include <iostream>
using namespace std;

// http://d.pr/n/1cADc
// 5_빌더
// : 동일한 구축공정을 사용하지만 각 공정의 표현이 달라지는 개체를 만들 때
struct IBuilder
{
	virtual void makeUniform() = 0;
	virtual void makeHat() = 0;
	virtual void makeShoes() = 0;

	virtual string getResult() = 0;

	virtual ~IBuilder() {}
}; 


// 축구 게임의 캐릭터를 만드는 공정은 변하지 않습니다.
class Director
{
	IBuilder* pBuilder;
public:
	void setBuilder(IBuilder* p) { pBuilder = p; }

	string construct() 
	{
		pBuilder->makeUniform();
		// pBuilder->makeHat();
		pBuilder->makeShoes();
	
		return pBuilder->getResult();
	}
};


// 다양한 나라 또는 팀의 빌더를 제공합니다.
class Korean : public IBuilder
{
	string s;
public:
	void makeHat() { s += "삿갓"; }
	void makeUniform() { s += "한복"; }
	void makeShoes() { s += "짚신"; }

	string getResult() { return s; }
};

class American : public IBuilder
{
	string s;
public:
	void makeHat() { s += "야구모자"; }
	void makeUniform() { s += "양복"; }
	void makeShoes() { s += "구두"; }

	string getResult() { return s; }
};

int main()
{
	Korean k; American a;

	Director d;
	d.setBuilder(&a);   // 캐릭터 선택 화살표키를 누르면 실행되는 코드
	cout << d.construct() << endl;
}
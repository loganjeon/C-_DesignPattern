// 5_함수와전략2
// http://d.pr/n/KJSe
// 1. 인라인 치환 문법은 컴파일 시간 문법이다.
// 2. 인라인 함수라도 함수 포인터에 담아서 호출하면 인라인 치환될 수 없다.
//   : 함수 포인터는 결국 변수이다. 실행 시간에 변할 수 있다.
       int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

int main()
{
	int n1 = add1(10, 20);
	int n2 = add2(10, 20);

	int(*f)(int, int) = &add2;
	f(10, 20);


}
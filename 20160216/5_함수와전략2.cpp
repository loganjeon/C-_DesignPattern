// 5_�Լ�������2
// http://d.pr/n/KJSe
// 1. �ζ��� ġȯ ������ ������ �ð� �����̴�.
// 2. �ζ��� �Լ��� �Լ� �����Ϳ� ��Ƽ� ȣ���ϸ� �ζ��� ġȯ�� �� ����.
//   : �Լ� �����ʹ� �ᱹ �����̴�. ���� �ð��� ���� �� �ִ�.
       int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

int main()
{
	int n1 = add1(10, 20);
	int n2 = add2(10, 20);

	int(*f)(int, int) = &add2;
	f(10, 20);


}
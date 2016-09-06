// 5_�Լ�������5


inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Greater {
	inline bool operator()(int a, int b) { return a < b; }
};

struct Less {
	inline bool operator()(int a, int b) { return a < b; }
};

#include <iostream>
using namespace std;

#include <algorithm> // ��å�� ���� ������ sort�� �̹� �ֽ��ϴ�.

// http://d.pr/n/12cM6
int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	// 2. ��å���� �Լ� ��ü�� ����� ��
	// ����: ��å�� �ζ��� ġȯ�ǹǷ� ������.
	// ����: ��å�� ��ü�� Ƚ�� ��ŭ�� sort() ���� �ڵ� ����
	Less less; Greater greater;
	sort(x, x + 10, less);     // sort(int*, int*, Less)�� �Լ� ����
	sort(x, x + 10, greater);  // sort(int*, int*, Greater)�� �Լ� ����

	// 1. ��å���� �Ϲ� �Լ��� ����� ��
	// ����: ��å�� ������ ��ü�ص� sort()�� ����� �ϳ��̴�.
	// ����: ��å�� �ζ��� ġȯ�� �Ұ����ϹǷ� ���� ���ϰ� �ִ�.
	sort(x, x + 10, cmp1);  // sort(int*, int*, bool(*)(int,int))�� �Լ� ����
	sort(x, x + 10, cmp2);  // �̹� ������ �Լ��� ����Ѵ�.

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;
}

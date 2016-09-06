#include <iostream>
using namespace std;
// �Լ��� ����
// http://d.pr/n/r6E3

// ������ �ʴ� ��ü �˰��򿡼� ���ؾ� �ϴ� ��å �ڵ�� �и��Ǿ�� �Ѵ�.
// �Ϲ� �Լ������� ���ؾ� �ϴ� ���� �Լ� ����(�Լ� ������)�� �и��Ѵ�.

void sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			// if (x[i] > x[j])
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	sort(x, 10, cmp2);

	for (int i = 0; i < 10; i++)
		cout << x[i] << endl;
}


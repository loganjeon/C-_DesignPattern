
// 4_protected������

// �ǵ� : �ڽ��� ���� �� ������(�߻��� ����),
//        �ڽ��� ���� �� �ְ� �ϰڴ�.
// http://d.pr/n/1cv9V
class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{

};

int main()
{
	Animal a; // error!
	Dog d;    // ok!
}
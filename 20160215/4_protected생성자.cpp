
// 4_protected생성자

// 의도 : 자신은 만들 수 없지만(추상적 존재),
//        자식은 만들 수 있게 하겠다.
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
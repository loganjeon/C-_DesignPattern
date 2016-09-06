// 1_참조계수5

// C++ 에서 참조 계수 기반 스마트 포인터를 만드는 2가지 형태
//	1. 참조 계수를 객체 안에 포함하는 방식 : 안드로이드 sp<>
//  sp<int> p1 = new int;  될까요?

//  sp는 RefBase의 자식 클래스만 사용 가능하다.
//  표준 타입은 사용이 불가능하다.
//  intrusive smart pointer 라고 부릅니다.

// 2. 참조 계수를 별도의 메모리로 관리하는 방식
// 표준에서 제공하는 shared_ptr<> 입니다.

// - shared_ptr<int> p1(new int);  // 이제 됩니다.
// - shared_ptr<int> p1 = make_shared<int>(10); 

// shared_ptr<>은 모든 타입에 사용이 가능합니다.
// 하지만 스마트포인터의 크기는 8바이트 이상입니다. (객체 포인터 + 참조 계수 포인터)
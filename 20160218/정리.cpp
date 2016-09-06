// 

// 정리
// C++ Idioms
// - CRTP, Thin Template, RAII, 함수객체, 스마트 포인터

// 객체지향 5대 원칙
// SRP : 단일 책임의 원칙 - 모듈은 단 하나의 책임을 가져야 한다.
// OCP : 개방 폐쇄의 원칙 - 모듈은 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
// LSP : 리스코프 치환 원칙 - 자식 클래스는 부모 클래스로 대체 가능해야 한다.
// ISP : 인터페이스 분리 원칙 - 범용 인터페이스보다는 세분화된 인터페이스 낫다.
// DIP : 의존 관계 역전 원칙 - 클라이언트는 구체 클래스에 의존하는 것이 아니라
//                             인터페이스나 추상 클래스에 의존해야 한다.

// GoF의 디자인 패턴 - 23가지
// 생성 5가지
//   싱글톤, 추상팩토리, 팩토리메소드, 프로토타입, (빌더)

// 구조 7가지
//   어댑터, (프락시), (브릿지), (퍼사드)
//   컴포지트, (포장지),
//   플라이웨이트

// 행위 11가지
//   반복자, 방문자       <= 컨테이너, 복합객체의 요소에 대한 패턴
//   관찰자, 책임의 전가  <= 하나의 요청을 여러곳에서 처리하는 패턴
//   Template Method, 전략, (상태)  <= 변화에 대응하는 패턴
//   Command                         <= 명령의 캡슐화
//   (Memento)    
//   중재자(Mediator)
//   인터프리터
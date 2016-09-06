
import java.util.Date;

// 1. getter를 필드를 복제해야 한다.
// 2. 불변 객체를 사용해야 한다.
//   Date : 잘못 설계되었습니다.

// 3. JAVA8 에서는 날짜 관련 API가 새롭게 설계되었습니다.
// 4. Apache Joda Time API


class Person
{
		private Date birth;

		public Person(Date birth) {
			this.birth = birth;
		}

		public Date getDate() {
			return this.birth.clone();
		}

		@Override
		public String toString() {
				return birth.toString();
		}
}


public class Test3 {
	public static void main(String[] args) {
			Person person = new Person(new Date());
			
			System.out.println(person);

			Date p = person.getDate();
			p.setYear(1999);

			System.out.println(person);
		
	}
}









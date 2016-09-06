

class Person
{
	String name;
	public Person(String name) {
		this.name = name;
	}

	public String getName() { return name; }
}


public class Test2 {
	public static void main(String[] args) {
			Person person = new Person("Chansik");
			String s = person.getName();

			s.replace("C", "B");
		
	}
}


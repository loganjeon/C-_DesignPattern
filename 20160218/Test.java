
public class Test {
	public static void main(String[] args) {
		String s1 = "aaa";
		String s2 = new String("aaa");   // Encoding...

		// 자바의 문자열은 불변 객체입니다.
		s1 = s1.replace("a", "b");  // "bbb"
		System.out.println(s1);
	}
}

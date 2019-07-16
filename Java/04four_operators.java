/**
 * 
 * @author Hing
 *
 */
public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x= 100;
		x = x / 100 * 100;
		System.out.println(x);
		
		
		int a = 2;
		int b;
		b = --a;
		System.out.println("a = " + a + "...b = " + b);
		
		int m = 2;
		m += 3;
		System.out.println(m);
		
		short s = 3;
//		s = s + 2 报错
		s = (short)(s + 2);
		s += 2;// += 在赋值时自动做了强制转换

	}
}
public class Car {
	String _color;
	int num;
	
	public void run() {
		System.out.println("color : " + _color);
		System.out.println("num : " + num);
	}
}
public class Demo {
	public static void main(String[] args) {
		Car c = new Car();
		c.run();
		c.num = 5;
		c.run();
		
		System.out.println("----------------");
		//��������ֻ��ʹ��һ��
		new Car().run();
		new Car().num = 5;
		new Car().run();
		
		System.out.println("----------------");
		System.out.println("----------------");
		
		method(new Car());
		method(new Car());
		method(new Car());
	}
	
	public static void method(Car cc) {
		cc.num = 10;
		cc.run();
	}
}

public class Swap {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int x = 3;
		int y = 6;
		//工作时这样写，面试时这样写比较low
		int temp;
		temp = x;
		x = y;
		y = temp;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
		
		x = 3;
		y = 6;
		//第一种
		//这种方式有安全隐患
		//如果x， y的值比较大，则溢出
		x = x + y;//x = 9;
		y = x - y;//y = 3;
		x = x - y;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
		
		x = 3;
		y = 6;
		/*
		 * 第三种，使用Java中的^位运算
		 * 效率最高，避免了超出int范围的问题
		 * 但是可读性差，这种形式只有 在面试时使用
		 * 工作时一般使用第三方变量
		 */
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
		System.out.println("x = " + x);
		System.out.println("y = " + y);

	}

}

/**
 * 	�������ģʽ
 * @author Hing 
 * 2019��8��1��
 * ����1:39:17
 *
 */

//����ʽ ������ʹ��
public class Single {
	//1.˽�л����캯��
	private Single() {}
	
	//2.����һ��˽�в��Ҿ�̬�ı������
	private static Single s = new Single();
	
	//3.����һ��������static�������ظö���
	public static Single getInstance() {
		return s;
	}
}
/*
//����ʽ ����ʱʹ��
public class Single2 {
	//1.˽�л����캯��
	private Single2() {}
	
	//2.����һ��˽�в��Ҿ�̬�ı������
	private static Single s = null;
	
	//3.����һ��������static�������ظö���
	public static Single getInstance() {
		if(s == null)
			s = new Single2();
		return s;
	}
}
*/

/*
public class SingleDemo {
	public static void main(String[] args) {
		Single s1 = Single.getInstance();
		Single s2 = Single.getInstance();
		
		System.out.println(s1 == s2);
	}
}
*/
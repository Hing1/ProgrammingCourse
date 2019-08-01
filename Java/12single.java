/**
 * 	单例设计模式
 * @author Hing 
 * 2019年8月1日
 * 下午1:39:17
 *
 */

//饿汉式 工作中使用
public class Single {
	//1.私有化构造函数
	private Single() {}
	
	//2.创建一个私有并且静态的本类对象
	private static Single s = new Single();
	
	//3.创建一个公共的static方法返回该对象
	public static Single getInstance() {
		return s;
	}
}
/*
//懒汉式 面试时使用
public class Single2 {
	//1.私有化构造函数
	private Single2() {}
	
	//2.创建一个私有并且静态的本类对象
	private static Single s = null;
	
	//3.创建一个公共的static方法返回该对象
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
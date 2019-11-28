public class Person {
	private int _age;
	private String _name;
	
	Person() {
		_age = 1;
	}
	Person(String name) {
		//调用下方 Person(int age) 函数
		//实现构造函数之间的调用，只能放在构造函数的第一行
		this(18);
		this._name = name;
	}
	Person(int age) {
		this._age = age;
	}
	Person(String name,int age) {
		_name = name;
		//_age = age;
		setAge(age);
	}
	
	public String getName() {
		return _name;
	}
	public void setName(String name) {
		_name = name;
	}
	public int getAge() {
		return _age;
	}
	public void setAge(int age) {
		if(age > 0 && age < 150) {
			_age = age;
		}else {
			System.out.println("Age figure illegal!!");
		}
		return;
	}

	public void speak() {
		System.out.println("My name is " + _name);
		System.out.println("I am " + _age);
	}
}

/**
 * 
 * @author Hing
 *
 */
public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int month = 3;
		switch (month) {
		case 3:
		case 4:
		case 5:
			System.out.println("springtime");
			break;
		case 6:
		case 7:
		case 8:
			System.out.println("summertime");
			break;
		case 9:
		case 10:
		case 11:
			System.out.println("autumn");
			break;
		case 12:
		case 1:
		case 2:
			System.out.println("wintertime");
			break;
		default:
			System.out.println("This month does not exist");
			break;
		}
	}
}
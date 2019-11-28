
public class Break {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		w:for (int i = 1; i <= 9; i++) {
			q:for (int j = 1; j <= 9; j++) {
				System.out.print(i * j);
				break w;//Ìø³öÁ½²ãÑ­»·
			}
		}
	}
}

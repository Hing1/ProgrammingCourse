
public class Swap {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int x = 3;
		int y = 6;
		//����ʱ����д������ʱ����д�Ƚ�low
		int temp;
		temp = x;
		x = y;
		y = temp;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
		
		x = 3;
		y = 6;
		//��һ��
		//���ַ�ʽ�а�ȫ����
		//���x�� y��ֵ�Ƚϴ������
		x = x + y;//x = 9;
		y = x - y;//y = 3;
		x = x - y;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
		
		x = 3;
		y = 6;
		/*
		 * �����֣�ʹ��Java�е�^λ����
		 * Ч����ߣ������˳���int��Χ������
		 * ���ǿɶ��Բ������ʽֻ�� ������ʱʹ��
		 * ����ʱһ��ʹ�õ���������
		 */
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
		System.out.println("x = " + x);
		System.out.println("y = " + y);

	}

}

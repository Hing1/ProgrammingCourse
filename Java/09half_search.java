/**
 *  二分查找
 *  数组必须是有序的
 *  
 *  */
public class Half_search {
	public static void main(String[] args) {
		int[] arr = {1,23,45,56,67,78,99};
		int index = halfSearch(arr, 23);
		System.out.println(index);
	}
	public static int halfSearch(int[] arr,int key) {
		int min = 0;
		int max = arr.length - 1;
		int mid = (min + max) / 2;
		while (arr[mid] != key) {
			if(key > arr[mid]) {
				min = mid + 1;
			}else {
				max = mid - 1;
			}
			mid = (min + max) / 2;
			if(min > max)
				return -1;
		}
		return mid;
	}
}

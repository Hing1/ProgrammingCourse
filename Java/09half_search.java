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
			// 如果min大于max，则说明数组中不存在这个元素，程序直接
			http://tv.wandhi.com/go.html?url=https%3A%2F%2Fv.youku.com%2Fv_show%2Fid_XNDI4MDk2MTg3Mg%3D%3D.html%3Fspm%3Da2h0j.11185381.listitem_page1.5!29~A%26%26s%3Defbfbd78efbfbd5cefbf
			if(min > max)
				return -1;
		}
		return mid;
	}
}

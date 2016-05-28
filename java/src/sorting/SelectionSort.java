package sorting;

public class SelectionSort {
	public static void main(String[] args ) {
		int[] data = new int[5];
		
		data[0] = 8;
		data[1] = 6;
		data[2] = 11;
		data[3] = 2;
		data[4] = 7;
			
		insertionSort(data);
		
		for(int j = 0; j < data.length; j++)
		{
			System.out.println(data[j]);
		}
		
		System.out.println("Find: " + find(data,2));
		
		
		String s = "cata";
		System.out.println("Dublicates: " + hasDuplicateChars(s));
	}
	
	// running time is independent of ordering of elements
	public static int[] selectionSort(int[] data) {
		int temp = 0;
		
		for(int i = 0; i < data.length ; i++){
			int minIndex = i;
			for(int j = i + 1; j < data.length; j++)
			{
				if (data[j] < data[minIndex])
				{
					minIndex = j;
				}
			}
			temp = data[minIndex];
			data[minIndex] = data[i];
			data[i] = temp;
		}
		return data;
	}
	
	// relatively good for small lists, relatively good for partially sorted lists
	public static int[] insertionSort(int[] data) {
		int current;
		int j;
		for(int i = 0; i < data.length; i++) {
			current = data[i];
			j = i - 1;
			while (j >= 0 && data[j] > current) {
				data[j+1] = data[j];
				j = j - 1;
			}
			data[j+1] = current;
		}
		return data;
	}
	
	public static int find(int[] data, int val) {
		int num = 0;
		
		if(data.length == 0){
			num = -1;
		}
		
		for (int i = 0; i< data.length; i++) {
			if(val == data[i])
			{
				num = val;
				return num;
			}
		}
		return 0;
	}
	
	//generics, sorting objects
	public void sort(Circle[] circles) {
		for (int i = 0; i < circles.length; i++) {
			Circle current = circles[i];
			int j = i - 1;
			
			while (j >= 0 && circles[j].getRadius() > current.getRadius()) {
				circles[j+1] = circles[j];
				j--;
			}
			
			circles[j+1] = current;
		}
	}
	
	public static boolean hasDuplicateChars(String s) {
		if(s.isEmpty())
			return false;
		
		char[] arr = s.toCharArray();
		for(int i = 0; i < s.length() - 1; i++) {
			for(int j = i + 1; j < s.length(); j++)
			{
				if(arr[i] == arr[j]){
					return true;
				}
			}
		}
		return false;
	}
}

package sorting;

import java.util.Arrays;

public class SortingDemo {
	public static void main(String[] args) {
		List listArray = new List();
		
		listArray.setData("abc");
		listArray.setData("sakdfj");
		
		//System.out.println(listArray.getString());
		
		
		String[] data = new String[26];
		//char alphabet = 'A';
		
//		for(char alphabet = 'A'; alphabet <= 'Z'; alphabet++)
//		{
//			System.out.println(alphabet);
//		}
		
		for(int i = 65; i <= 90; i++) {
			System.out.println((char)i);
		}
		//Arrays.sort(data);
		
		for(int i = 0; i < 10; i++) {
			System.out.println(data[i]);
		}
		
	}
	
}
		
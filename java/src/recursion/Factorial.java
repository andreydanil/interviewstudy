package Recursion;

public class Factorial {
	public static void main(String[] args) {
		System.out.println(factorial(8));
	}
	
	public static int factorial(int n) {
		if(n == 0) return 1;
		else if(n < 0) return -1;
		return n *factorial(n-1);
	}
	
	public static int tailFactorial(int n, int result) {
		if (n == 0) return result;
		return tailFactorial(n-1, n*result);
	}
}
  
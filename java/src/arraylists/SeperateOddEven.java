package Arraylists;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class SeperateOddEven {

    static Integer [] arr = { 1, 3, 5, 6, 7, 8, 9, 10};

    /**
     * Separate even and odd integers in a given array
     * @param args
     */
    public static void main(String[] args) {
        System.out.println("Separate even and odd integers in a given array../");

        for(int i=0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\n");
        seperateOddEven();
    }

    public static void seperateOddEven() {
        ArrayList<Integer> odd = new ArrayList<Integer>();
        ArrayList<Integer> even = new ArrayList<Integer>();

        for(int i=0; i < arr.length; i++) {
            if(arr[i] % 2 == 0) {
                even.add(arr[i]);
            } else {
                odd.add(arr[i]);
            }
        }

        System.out.println("Even: " + even.toString());
        System.out.println("Odd: " + odd.toString());
    }
}

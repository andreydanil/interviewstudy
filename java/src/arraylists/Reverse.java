package Arraylists;

import java.util.Arrays;

public class Reverse {

    public static void main(String[] args) {
        final int [] array = { 1 ,2, 3, 4, 5, 6, 7 };
        System.out.println(Arrays.toString(array));
        reverse(array);

    }

    public static void reverse(int[] array) {
        int temp = 0;
        int swap = 0;
        for(int i = 0; i < array.length / 2; i++) {
            temp = array[i];
            swap = array[array.length-i-1];

            array[array.length-i-1] = temp;
            array[i] = swap;
        }
        System.out.println(Arrays.toString(array));

    }
}

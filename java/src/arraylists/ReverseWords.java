package Arraylists;

import java.util.ArrayList;

public class ReverseWords {

    static String[] words = {"First" , "Second", "Third", "Fourth", "Fifth"};
    public static void main(String[] args) {
        System.out.println("Reversing the words in a string array");

        System.out.println("Original: \n");
        for(int i = 0; i < words.length; i++) {
            System.out.println(words[i]);
        }

        String[] tempArray = new String[words.length];

        for(int i = 0; i<=words.length / 2; i++) {
            String temp = words[i];
            tempArray[i] = words[words.length - i - 1];
            tempArray[words.length - i - 1] = temp;

        }

        System.out.println("Reversed: \n");
        for(int i = 0; i < tempArray.length; i++) {
            System.out.println(tempArray[i]);
        }



    }
}

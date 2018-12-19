package Strings;

import java.util.HashMap;

/**
 * Implement an algorithm to determine if a string has all unique characters.
 */
public class Unique {
    public static void main(String[] args) {
        String word = "Are the characters unique?";
        System.out.println(isUnique(word));
    }

    public static boolean isUnique(String word) {
        HashMap<Character,Boolean> unique = new HashMap<Character, Boolean>();
        char[] str = word.toCharArray();
        int size = word.length();

        System.out.println("Character array: " + str.toString());

        for(int i = 0; i < size; i++) {

            if(unique.get(str[i]) == null) {
                unique.put(str[i],true);
            }
            else if(unique.containsKey(str[i]) == true){
                System.out.println("The duplicate letter is: " + str[i]);
                return false;
            }
        }

        System.out.println("There are no duplicates");

        return true;
    }
}

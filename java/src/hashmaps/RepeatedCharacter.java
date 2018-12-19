package Hashmaps;

import java.util.HashMap;

public class RepeatedCharacter {

    private static String message = "12341234123412341";

    public static void main(String[] args) throws Exception {
        System.out.println(checkRepeated(message));
    }

    public static boolean checkRepeated(String message) throws Exception {
        int length = message.length();
        char[] characters = message.toCharArray();
        HashMap<Character,Boolean> map = new HashMap<Character, Boolean>();

        if (length < 1)
            return false;

        for(int i = 0; i<length; i++) {
            if(!map.containsKey(characters[i])) {
                // add to map
                map.put(characters[i],true);
            }
            else if (map.containsKey(characters[i])) {
                // repeated element exists
                return true;
            }
        }
        return false;
    }
}


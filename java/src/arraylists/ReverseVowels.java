package Arraylists;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * PROBLEM
 * reverseVowel(“AEIOU”) => “UOIEA”
 * reverseVowel(“QWRT”) => “QWRT”
 * reverseVowel(“UNITED STATES”) => “ENATED STITUS”
 */

public class ReverseVowels {

    public static void main(String[] args) {
        String word = "AEIOU";
        System.out.println(reverse(word));
    }

    private static String reverse(String word) {

        char[] letters = word.toCharArray();
        int size = word.length();
        ArrayList vowels = new ArrayList();
        HashMap<Integer,Character> vowelsMap = new HashMap<Integer, Character>();

        for(int i = 0; i < size; i++)
        {
            if(letters[i] == 'A' || letters[i] == 'a' || letters[i] == 'I' || letters[i] == 'i'
                    || letters[i] == 'O' || letters[i] == 'o' || letters[i] == 'U' ||
                    letters[i] == 'u' || letters[i] == 'O' || letters[i] == 'o' ||
                    letters[i] == 'E' || letters[i] == 'e' || letters[i] == 'Y' || letters[i] == 'y' )
            {
                vowels.add(letters[i]);

                vowelsMap.put(i, letters[i]);
            }
        }
        System.out.println(vowels.toString());
        System.out.println(vowelsMap.toString());

        for(int j = 0; j < vowelsMap.size(); j++) {
            char temp = vowelsMap.get(j);
            char swap = vowelsMap.get(vowelsMap.size() - j - 1);

            vowelsMap.put(j, swap);
            vowelsMap.put(vowelsMap.size() - j - 1, temp);
        }

        System.out.println(vowelsMap.toString());





        return null;
    }

}

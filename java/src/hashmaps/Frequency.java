package Hashmaps;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Frequency {
    // Print frequency
    public static void main(String[] args) {
        Integer numbers[] = { 1, 2, 3, 5, 5, 8, 10 };
        System.out.println(Arrays.toString(numbers));
        frequency(numbers);

    }

    public static void frequency(Integer numbers []) {

        HashMap<Integer,Integer> frequencyMap = new HashMap<Integer, Integer>();

        for(int i = 0; i < numbers.length; i++) {

            Integer c = frequencyMap.get(numbers[i]);

            // if occurs
            if(frequencyMap.get(numbers[i]) == null)
                frequencyMap.put(numbers[i], 1);

                // if element already exist in hashmap
            else
                frequencyMap.put(numbers[i], ++c);

        }

        // print results
        for (Map.Entry m:frequencyMap.entrySet())
            System.out.println("Frequency of " + m.getKey() + " is " + m.getValue());

    }
}

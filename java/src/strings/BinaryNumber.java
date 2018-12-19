package Strings;

import java.util.HashMap;

public class BinaryNumber {

    public static void main(String[] args) {
        HashMap<Integer,Integer> binaryWeights = new HashMap<Integer,Integer>();

        String binaryString = "1011"; // 11

        binaryWeights.put(3,1);
        binaryWeights.put(2,2);
        binaryWeights.put(1,4);
        binaryWeights.put(0,8);

        char[] arr = binaryString.toCharArray();
        int binarySum = 0;

        for (int i = 0 ; i < binaryString.length(); i++) {
            if(arr[i] == '1') {
                binarySum += binaryWeights.get(i);
                System.out.println("Adding: " + binaryWeights.get(i));
            }
        }

        System.out.println(binarySum);

    }
}

package Arraylists;

import java.util.Arrays;

public class SumTriplet {

    public static int[] numbers = {1,2,-3};

    public static void main(String[] args) {
        System.out.println("Check if sum equals a number");
        System.out.println("Array " + Arrays.toString(numbers));
        System.out.println(sumTripletNaive(numbers,numbers.length,0, false));
        System.out.println(sumTripletAlgo(numbers,numbers.length,0, false));

    }

    /**
     * Method 1: naive O(N^2)
     * @param numbers
     * @param length
     * @param sum
     * @return
     */
    public static boolean sumTripletNaive(int[] numbers, int length, int sum, boolean flag) {

        if(!flag) {
            for(int i=0;i<length-2;i++){
                for(int j=i+1;j<length-1;j++){
                    for(int k=j+1;k<length;k++){
                        if(numbers[i] + numbers[j] + numbers[k] == sum)
                            return true;
                    }
                }
            }
        }

        // sum not found
        return false;
    }

    /**
     * Method 2: algo O(N^2)
     * @param numbers
     * @param length
     * @param sum
     * @param flag
     * @return
     */
    public static boolean sumTripletAlgo(int[] numbers, int length, int sum, boolean flag) {


        int leftIndex, rightIndex = 0;

        if(flag) {
            
        }

        // sum not found
        return false;

    }
}

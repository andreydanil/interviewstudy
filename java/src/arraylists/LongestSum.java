package Arraylists;

import java.util.*;

public class LongestSum {

    public static int[] arr = {2, -8, 3, -2, 4, -10};

    public static void main(String[] args) {


        Random random = new Random();
        int number = random.nextInt(arr.length);
        System.out.println(number);

        System.out.println("longest sum: " + longestSum(arr));

        Hashtable<Integer, String> table = new Hashtable<Integer, String>();
        table.put(1,"hello-table");

        HashMap<Integer,String> map = new HashMap<Integer, String>();
        map.put(1,"hello-map");
        map.put(2,"hello-map-2");

        System.out.println("table " + table.get(1));
        System.out.println("map " + map.get(1));

        for(Integer key: map.keySet()) {
            System.out.println("PRINTING KEY - " + key);
        }

        for(HashMap.Entry<Integer,String> entry : map.entrySet()) {
            Integer key = entry.getKey();
            String value = entry.getValue();
        }


        LinkedHashMap lhm = new LinkedHashMap();

        // Put elements to the map
        lhm.put("Zara", new Double(3434.34));
        lhm.put("Mahnaz", new Double(123.22));
        lhm.put("Ayan", new Double(1378.00));
        lhm.put("Daisy", new Double(99.22));
        lhm.put("Qadir", new Double(-19.08));

        // Get a set of the entries
        Set set = lhm.entrySet();

        // Get an iterator
        Iterator i = set.iterator();

        // Display elements
        while(i.hasNext()) {
            Map.Entry me = (Map.Entry)i.next();
            System.out.print(me.getKey() + ": ");
            System.out.println(me.getValue());
        }
        System.out.println();

        // Deposit 1000 into Zara's account
        double balance = ((Double)lhm.get("Zara")).doubleValue();
        lhm.put("Zara", new Double(balance + 1000));
        System.out.println("Zara's new balance: " + lhm.get("Zara"));
    }

    private static int longestSum(int[] arr) {
        if(arr.length == 0)
            return 0;
        int temp;
        int longestSum = 0;

        for(int i = 0; i < arr.length; i++) {
            temp = arr[i];
            System.out.println(temp);
            for(int j = i+1; j < arr.length - 1; j++) {
                temp = temp + arr[j];
                System.out.println("temp: " + temp);
                if(temp > longestSum) {
                    longestSum = temp;
                }
            }
        }

        return longestSum;
    }
}

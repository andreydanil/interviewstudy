package Arraylists;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class InArray {

//    static int[] bucket1 = {1,2};
//    static int[] bucket2 = {1,2,3,4};

    public static void main(String[] args) {
        Collection firstList = new ArrayList() {{
            add("apple");
            add("orange");
        }};

        Collection bucket1 = new ArrayList() {{
            add("1");
            add("2");
        }};
        bucket1.add("4");


        Collection secondList = new ArrayList() {{
            add("apple");
            add("orange");
            add("banana");
            add("strawberry");
        }};

        int[] bucket2 = {1,2,3,4};
        //Collection collection2 = Collections.singleton(bucket2);
        //collection2.add("7");

        System.out.println(bucket1);

        // Show the "before" lists
        System.out.println("First List: " + firstList);
        System.out.println("Second List: " + secondList);

        // Remove all elements in firstList from secondList
        secondList.removeAll(firstList);

        // Show the "after" list
        System.out.println("Result: " + secondList);

    }
}

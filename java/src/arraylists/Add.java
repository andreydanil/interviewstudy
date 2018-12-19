package Arraylists;

import java.util.ArrayList;
import java.util.Arrays;

public class Add {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();

        list.add("Chicago");

        System.out.println(list.get(0));

        list.add("New York");
        list.add("Seattle");
        list.add("Los Angeles");

        System.out.println(Arrays.toString(new ArrayList[]{list}));

    }

    public void reverse(ArrayList<String> list) {

    }

}

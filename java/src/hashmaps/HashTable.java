package Hashmaps;

import java.util.Hashtable;
import java.util.Iterator;

public class HashTable {

    public static void main(String[] args) {
        Hashtable<String,String> values = new Hashtable<String, String>();
        values.put("new","type");


        for(String key: values.keySet()) {
            System.out.println(key);
        }





    }
}

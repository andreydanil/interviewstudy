package com.js.HashMap;

import java.util.HashMap;

class HashMapIterator {
	public static void main(String[] args) {
		
		/**
		 * creates an empty HashMap instance
		 */
		
		Map map = new HashMap();
		
		/**
		 * insert values into map, using put() method
		 */
		map.put("ONE", 1);
		map.put("TWO", 2);
		
		/**
		 * get the set of keys from HashMap
		 */
		Set setOfKeys = map.keySet();
		
		while (iterator.hasNext()) {
			String key = (String) iterator.next();
			
			Integer value = (Integer)map.get(key);
			
			System.out.println("Key: " + key +", Value" + value);
		}
	}
}
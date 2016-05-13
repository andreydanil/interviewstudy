package linkedList;

//incorrectness of an algorithm 
//STEP 1 Give a set of data which the algorithm does not not.

//analysis of algorithms
//BIG O 
//- how much space does it take in memory (space complexity)
//- how much time does it take to run (time complexity)

//Linked list
//Node - data (primitive or object reference), nextNode (reference)
//Head - first element
//Points to null at the end

// Only reference is the head element
// Insert new node at the head

// constant n(1)
// linear O(n)

public class Node {
	
	private int data;
	private Node nextNode;
	
	// constructor 
	public Node (int data) {
		this.data = data;
	}
	 
	// getter
	public int getData() {
		return this.data;
	}
	
	// getter
	public Node getNextNode() {
		return this.nextNode;
	}
	
	// setter
	public void setData(int data) {
		this.data = data;
	}
	
	// setter
	public void setNextNode(Node nextNode) {
		this.nextNode = nextNode;
	}
	
	@Override
	public String toString() {
		return "Data: " + this.data;
	}
	
}

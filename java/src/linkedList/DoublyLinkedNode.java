package linkedList;

public class DoublyLinkedNode {
	//member variable
	
	//reference to Nodes
	private int data;
	private DoublyLinkedNode nextNode;
	
	public DoublyLinkedNode (int data) {
		this.data = data;
	}
	
	public int getData() {
		return data;
	}
	public void setData(int data) {
		this.data = data;
	}
	public DoublyLinkedNode getNextNode() {
		return nextNode;
	}
	public void setNextNode(DoublyLinkedNode nextNode) {
		this.nextNode = nextNode;
	}
	public DoublyLinkedNode getPreviousNode() {
		return previousNode;
	}
	public void setPreviousNode(DoublyLinkedNode previousNode) {
		this.previousNode = previousNode;
	}
	private DoublyLinkedNode previousNode;

}

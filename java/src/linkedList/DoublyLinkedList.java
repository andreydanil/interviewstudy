package linkedList;

public class DoublyLinkedList {
	//member variable
	private DoublyLinkedNode head;
	
	public void insertAtHead (int data) {
		DoublyLinkedNode newNode = new DoublyLinkedNode(data);
		newNode.setNextNode(this.head);
		if (this.head != null) {
			this.head.setPreviousNode(newNode);
		}
		this.head = newNode;
	}
	
	public int length() {
		int length = 0;
		if(head == null)
			return 0;
		
		DoublyLinkedNode current = this.head;
		
		while (current != null) {
			length +=1;
			current = current.getNextNode();
		}
		return length;
	}
}

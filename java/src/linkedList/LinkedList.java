package linkedList;

public class LinkedList {
	private Node head;
	
	public void insertAtHead (int data) {
		Node newNode = new Node(data);
		newNode.setNextNode(this.head);
		this.head = newNode;
	}
	
	public int length() {
		int length = 0;
		Node current = this.head;
		
		while (current != null) {
			length ++;
			current = current.getNextNode();
		}
		return length;
	}
	
	public void deleteFromHead() {
		this.head = this.head.getNextNode();
	}
	
	public Node find (int data) {
		Node current = this.head;
		
		while (current != null)
		{
			if (current.getData() == data) {
				return current;
			}
			current = current.getNextNode();
		}
		return null;
	}
	
	public void reverse()
	{
		Node current = this.head;
		Node next = current.getNextNode();
		current = null;
		while(current != null)
		{
			//TODO
			// who is you developer manager
			
		}
	}
	
	@Override
	public String toString() {
		String result = "{";
		Node current = this.head;
		
		while (current != null) {
			if(current.getNextNode() == null) {
				result += current.toString();
			}
			else 
			{
				result += current.toString() + ", ";
			}
			current = current.getNextNode();
		}
		
		result += "}";
		return result;
	}
}

package linkedList;

public class DoublyLinkedListDemo {
	public static void main(String[] args) {
		DoublyLinkedList integers = new DoublyLinkedList();
		
		integers.insertAtHead(5);
		integers.insertAtHead(12);
		integers.insertAtHead(3);
		integers.insertAtHead(18);
		integers.insertAtHead(23);
		integers.insertAtHead(2);
		
		System.out.println(integers);
	}
}

package linkedList;

public class DoublyEndedListDemo {
	public static void main(String[] args) {
		DoublyEndedList dList = new DoublyEndedList();
		
		dList.insertAtTail(19);
		dList.insertAtTail(18);
		dList.insertAtTail(17);
		
		System.out.println(dList);
	}
}

package Linkedlists;

public class SingleLinkedList {

    private static Node head;

    public static void main(String[] args) {
        System.out.println("Implementing linked list");

        SingleLinkedList list = new SingleLinkedList();

        list.insert(1);
        list.insert(2);
        list.insert(4);
        list.insert(5);
        //list.delete(4);



        System.out.println(getCount(head));


    }

    private void delete(int data) {
        if(data < 0) {
            return;
        }

        Node current = head;
        Node prev = head;
        Node next = head.next;
        int counter = 0;

        while(current.data != data) {
            current = current.next;
            if(current.data == data) {
                prev = current.next;
                current = null;

            }
        }
    }

    public static int getCount(Node head) {
        if (head == null) {
            return 0;
        }
        int count = 0;

        while(head != null) {
            head = head.next;
            count++;
        }
        return count;
    }
    private void insert(int data) {
        Node newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    public Node reverse() {
        Node result = null;
        Node current = this.head;
        Node next = null;
        while(current != null) {
            next = current.next;
            next = result;
            result = current;
            current = next;
        }
        this.head = result;

        return result;
    }
    public void print() {
        String result = "{";
        Node current = this.head;

        while(current != null) {
            if (current.next == null) {
                result += current.toString();
            } else {
                result += current.toString() + ", ";
            }
        }

        result += "}";

        System.out.println(result);
    }
}

/**
 * Linked list data structure
 */
class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
    }
}
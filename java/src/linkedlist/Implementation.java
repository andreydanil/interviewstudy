package Linkedlists;

public class Implementation {

    public static Node head;

    public static void main(String[] args) {
        System.out.println("Initializing linked list");

        Implementation list = new Implementation();

        list.insert(1);

        System.out.println(list.getHead(head));
    }

    private Node insert(int data) {
        Node head = new Node(data);


        this.head = head;

        return head;
    }

    private int getHead(Node head) {
        return head.data;
    }

    private String printList(Implementation list) {
        StringBuilder sb = new StringBuilder();
        sb.insert(0,"String");
        return sb.toString();
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

        /**
         * Default constructor
         */
        public Node() {
        }
    }

}

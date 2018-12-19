package Trees;

import javax.swing.tree.TreeNode;
import java.util.Arrays;

/**
 * Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height
 */
public class ArrayToTree {
    
    public  static Integer [] numbers = { 1, 3, 4, 6, 8, 10, 40, 70 };

    public static class BinarySearchTree {
        
        private Node root;
        
        public void insert(Integer data) {
            if(root == null)
                this.root = new Node(data);
            else 
                root.insert(data);
            
        }

        public Node find(Integer data) {
            if(root != null) {
                return root.find(data);
            }
            return null;
        }
        
    }
    public static class Node {
        int data;
        Node leftChild;
        Node rightChild;

        // Constructor for data
        public Node(int data) {
            this.data = data;
        }

        // Constructor for the data and references to children
        public Node(int data, Node leftChild, Node rightChild) {
            this.data = data;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
        }

        public void insert(Integer data) {
            if(data >= this.data)
            {
                if (this.rightChild == null)
                    this.rightChild = new Node(data);
                else
                    this.rightChild.insert(data);
            } else {
                if (this.leftChild == null)
                    this.leftChild = new Node(data);
                else
                    this.leftChild.insert(data);
            }
        }

        public Node find(Integer data) {
            if (this.data == data) {
                return this;
            }
            if (data < this.data && leftChild != null) {
                return leftChild.find(data);
            }
            if (rightChild != null) {
                return rightChild.find(data);
            }
            return null;
        }
    }

    public static void main(String[] args) {

        System.out.println("Putting array in to a BST");

        BinarySearchTree BST = new BinarySearchTree();

        for(int i = 0; i < numbers.length; i++){
            BST.insert(numbers[i]);
        }

        System.out.println(BST.find(1));


    }
}

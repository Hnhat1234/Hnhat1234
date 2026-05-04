package com.example;

class Node {
    String key;
    Node left, right;

    public Node(String item) {
        key = item;
        left = right = null;
    }
}

class BinarySearchTree {
    Node root;

    public BinarySearchTree() {
        root = null;
    }

    // Insertion operation
    void insert(String key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node root, String key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key.compareTo(root.key) < 0)
            root.left = insertRec(root.left, key);
        else if (key.compareTo((root.key)) > 0)
            root.right = insertRec(root.right, key);

        return root;
    }

    // Deletion operation
    void delete(String key) {
        root = deleteRec(root, key);
    }

    Node deleteRec(Node root, String key) {
        if (root == null)
            return root;

        if (key.compareTo(root.key) < 0)
            root.left = deleteRec(root.left, key);
        else if (key.compareTo(root.key) > 0)
            root.right = deleteRec(root.right, key);
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            root.key = minValue(root.right);

            root.right = deleteRec(root.right, root.key);
        }

        return root;
    }

    String minValue(Node root) {
        String minv = root.key;
        while (root.left != null) {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    // Search operation
    boolean search(String key) {
        return searchRec(root, key);
    }

    boolean searchRec(Node root, String key) {
        if (root == null)
            return false;
        if (key.compareTo(root.key) == 0)
            return true;
        if (key.compareTo(root.key) > 0)
            return searchRec(root.right, key);
        return searchRec(root.left, key);
    }

    // Inorder traversal
    void inorder() {
        inorderRec(root);
        System.out.println("\n");
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }

    // Preorder traversal
    void preorder() {
        preorderRec(root);
        System.out.println("\n");

    }

    void preorderRec(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }

    // Postorder traversal
    void postorder() {
        postorderRec(root);
        System.out.println("\n");
    }

    void postorderRec(Node root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.key + " ");
        }
    }

    // Print beautiful tree diagram
    void printTree() {
        System.out.println();
        System.out.println("Tree Structure:");
        printTreeRec(root, "", true, true);
        System.out.println();
    }

    void printTreeRec(Node node, String prefix, boolean isTail, boolean isRoot) {
        if (node == null) return;
        String nodeLabel = isRoot ? "[ROOT] " + node.key : node.key;
        System.out.println(prefix + (isTail ? "└── " : "├── ") + nodeLabel);
        // Count children
        int children = 0;
        if (node.left != null) children++;
        if (node.right != null) children++;
        if (children == 0) return;
        if (node.left != null && node.right != null) {
            printTreeRec(node.left, prefix + (isTail ? "    " : "│   "), false, false);
            printTreeRec(node.right, prefix + (isTail ? "    " : "│   "), true, false);
        } else if (node.left != null) {
            printTreeRec(node.left, prefix + (isTail ? "    " : "│   "), true, false);
        } else {
            printTreeRec(node.right, prefix + (isTail ? "    " : "│   "), true, false);
        }
    }

}

// Driver Class
public class Main {
    // Main Function
    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();

        // Inserting elements
        tree.insert("50a");
        tree.insert("30b");
        tree.insert("20c");
        tree.insert("40d");
        tree.insert("70e");
        tree.insert("60f");
        tree.insert("80g");

        // Print tree diagram
        System.out.println("Tree diagram:");
        tree.printTree();
    }
}
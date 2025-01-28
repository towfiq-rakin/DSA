class Tree<T extends Comparable<T>> {
    static class Node<T> {
        T data;
        Node<T> left;
        Node<T> right;
        Node(T data) {
            this.data = data;
            left = right = null;
        }
    }
    private Node<T> root;
    private Node<T> insertNode(Node<T> temp, T data){
        if(temp == null)
            return new Node<>(data);
        if(data.compareTo(temp.data) < 0)
            temp.left = insertNode(temp.left, data);
        else
            temp.right = insertNode(temp.right, data);
        return temp;
    }

    private void inorderH(Node<T> temp){
        if(temp == null) return;
        inorderH(temp.left);
        System.out.print(temp.data + " ");
        inorderH(temp.right);
    }

    private void preorderH(Node<T> temp){
        if(temp == null) return;
        System.out.print(temp.data + " ");
        preorderH(temp.left);
        preorderH(temp.right);
    }

    private void postorderH(Node<T> temp){
        if(temp == null) return;
        postorderH(temp.left);
        postorderH(temp.right);
        System.out.print(temp.data + " ");
    }

    public Tree(){
        root = null;
    }

    public void insert(T data){
        root = insertNode(root, data);
    }

    public void inorder(){
        inorderH(root);
    }

    public void preorder(){
        preorderH(root);
    }

    public void postorder(){
        postorderH(root);
    }
}

public class BST {
    public static void main(String[] args){
        Tree<Integer> t = new Tree<>();
        t.insert(8);
        t.insert(3);
        t.insert(10);
        t.insert(1);
        t.insert(6);
        t.insert(14);
        t.insert(4);
        t.insert(7);
        t.insert(13);

        System.out.println("Inorder: ");
        t.inorder();
        System.out.println();

        System.out.println("Pre: ");
        t.preorder();
        System.out.println();

        System.out.println("Post: ");
        t.postorder();
        System.out.println();
    }
}

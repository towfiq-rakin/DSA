/*
    # Binary Search Tree (BST) 

    * Travaersal Techniques
        - Inorder
        - Preorder
        - Postorder
        - Level order
    * Search
    * Insert
    * Delete

*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper recursive function to insert a new node
    // Time complexity: O(h), where h is the height of the tree
    // Smaller values go to the left, larger values go to the right
    Node* insertNode(Node* curr, T val) {
        if (curr == nullptr) {
            return new Node(val);
        }
        if (val < curr->data) {
            curr->left = insertNode(curr->left, val);
        } else {
            curr->right = insertNode(curr->right, val);
        }
        return curr;
    }

    // Helper function for inorder traversal
    // left -> root -> right
    void inorderHelper(Node* curr) {
        if (!curr) return;
        inorderHelper(curr->left);
        cout << curr->data << " ";
        inorderHelper(curr->right);
    }

    // Helper function for preorder traversal
    // root -> left -> right
    void preorderHelper(Node* curr) {
        if (!curr) return;
        cout << curr->data << " ";
        preorderHelper(curr->left);
        preorderHelper(curr->right);
    }

    // Helper function for postorder traversal
    // left -> right -> root
    void postorderHelper(Node* curr) {
        if (!curr) return;
        postorderHelper(curr->left);
        postorderHelper(curr->right);
        cout << curr->data << " ";
    }

    // Helper function to search for a value
    // Time complexity: O(h), where h is the height of the tree
    bool searchHelper(Node* curr, T val) {
        if (!curr) return false;
        if (curr->data == val) return true;
        if (val < curr->data) return searchHelper(curr->left, val);
        return searchHelper(curr->right, val);
    }

    // Helper function to delete a tree
    void deleteTree(Node* curr) {
        if (!curr) return;
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }

    // Helper function to delete a node
    void deleteHelper(Node* curr, T val) {
        if (curr == nullptr) return; // Value not found or Empty tree
        if (curr->data == val) {
            if (curr->left == nullptr && curr->right == nullptr) { // Leaf node
                delete curr;
                curr = nullptr;
            } else if (curr->left == nullptr) { // Node with only right child
                Node* temp = curr;
                curr = curr->right;
                delete temp;
            } else if (curr->right == nullptr) { // Node with only left child
                Node* temp = curr;
                curr = curr->left;
                delete temp;
            } else {
                Node* temp = curr->right; // Node with two children
                while (temp->left) {
                    temp = temp->left;
                }
                curr->data = temp->data;
                deleteHelper(curr->right, temp->data); 
                // Here Im replacing with the inorder successor, Which is the smallest element in the right subtree
            }
        } else if (val < curr->data) {
            deleteHelper(curr->left, val); // Value is smaller, go to the left subtree
        } else {
            deleteHelper(curr->right, val); // Value is larger, go to the right subtree
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert a new node
    void insert(T val) {
        root = insertNode(root, val);
    }

    // Inorder traversal
    void inorder() {
        inorderHelper(root);
    }

    // Preorder traversal
    void preorder() {
        preorderHelper(root);
    }

    // Postorder traversal
    void postorder() {
        postorderHelper(root);
    }

    // Level order traversal
    // Time complexity: O(n), where n is the number of nodes in the tree
    void levelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }

    // Delete a node
    void deleteNode(T val) {
        deleteHelper(root, val);
    }
    // Search for a value
    bool search(T val) {
        return searchHelper(root, val);
    }
};


int main() {
    BinaryTree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);

    // For User Input
    
    // int n;
    // cout << "Enter the number of elements: "; cin >> n;
    // cout << "Enter the elements: ";
    // for(int i = 0; i < n; i++){
    //     int x; cin >> x;
    //     tree.insert(x);
    // }
    

    cout << "Inorder: ";
    tree.inorder(); 
    cout << endl;

    cout << "Preorder: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder: ";
    tree.postorder();
    cout << endl;

    cout << "Level order: ";
    tree.levelOrder();
    cout << endl;

    cout << "Search for 6: " << tree.search(6) << endl;
    cout << "Search for 11: " << tree.search(11) << endl;

    tree.deleteNode(61);
    cout << "Inorder after deleting 61: ";
    tree.inorder();
    cout << endl;

    cout << "Level order after deleting 61: ";
    tree.levelOrder();
    cout << endl;

    return 0;
}

/*
    Graphical Representation of the tree:
    
                8
               / \
              3   10
             / \    \
            1   6    14
               / \   /
              4   7 13
*/

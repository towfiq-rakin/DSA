/*
    ! Doubly Linked List
    - A doubly linked list is a linked data structure that consists 
    of a set of sequentially linked records called nodes.

    * Advantages of Doubly Linked List:
    - It can be traversed in both forward and backward direction.
    - The deletion of a node is easy as compared to singly linked list.
    - We can quickly insert a new node at last. O(1) time complexity.

*/

#include <iostream>
using namespace std;
#define endl "\n"

template <typename T>
class list {
    struct Node {
        T data;
        Node* next;
        Node* prev; 
    };
    Node* head; // head of the list
    Node* tail; // tail of the list
    int count; // size of the list

public:
    list() : head(nullptr), tail(nullptr), count(0) {} // Constructor

    // Print the list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print the list in reverse order
    void print_reverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Push the element at the front of the list
    void pushfront(T data) {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = head;
        newnode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newnode;
        }
        head = newnode;
        if (tail == nullptr) {
            tail = newnode;
        }
        ++count;
    }

    // Push the element at the back of the list
    void pushback(T data) {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = nullptr;
        newnode->prev = tail;
        if (tail != nullptr) {
            tail->next = newnode;
        }
        tail = newnode;
        if (head == nullptr) {
            head = newnode;
        }
        ++count;
    }

    // Insert the element after a specific node
    void insert_node(T key, T data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                Node* newnode = new Node;
                newnode->data = data;
                newnode->next = temp->next;
                newnode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newnode;
                } else {
                    tail = newnode;
                }
                temp->next = newnode;
                ++count;
                return;
            }
            temp = temp->next;
        }
    }
    
    // Pop the element from the front of the list
    void popfront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --count;
    }

    // Pop the element from the back of the list
    void popback() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        --count;
    }

    // Delete the specific node from the list
    void delete_node(T key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }
                delete temp;
                --count;
                return;
            }
            temp = temp->next;
        }
    }

    // Get the front element of the list
    T front() {
        return head->data;
    }

    // Get the back element of the list
    T back() {
        return tail->data;
    }

    // Get the size of the list
    int size() const {
        return count;
    }

    // Check if the list is empty
    bool empty() const {
        return count == 0;
    }
};

int main() {
    list<int> dll;
    dll.pushfront(10);
    dll.pushfront(20);
    dll.pushback(30);
    dll.pushback(40);

    cout << "List after pushing elements: ";
    dll.print();

    dll.popfront();
    cout << "List after popping front: ";
    dll.print();

    dll.popback();
    cout << "List after popping back: ";
    dll.print();

    cout << "Size of the list: " << dll.size() << endl;
    cout << "Is the list empty? " << (dll.empty() ? "Yes" : "No") << endl;

    return 0;
}

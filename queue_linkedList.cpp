/*
    *Queue using Linked List*

#   Queue is a linear data structure that follows the FIFO (First In First Out) rule. 
#   In a queue, the element that is inserted first is the first one to be removed.
    Thus, we will push the element at the rear of the queue 
    and pop the element from the front of the queue.
#   The queue can be implemented using an array or a linked list. 
    In this code snippet, we will implement a queue using a linked list.
*/

#include<iostream>
using namespace std;
#define endl "\n"

template <typename T>
class queue{
    struct Node{
        T data; // you can use int here instead of T
        Node* next;
    };
    Node* head; // Front of the queue
    Node* tail; // Rear of the queue
    int count; // size of the queue

    public:
    queue() : head(nullptr), tail(nullptr), count(0) {} // Constructor

    // Check if the queue is empty
    bool empty(){
        return head == nullptr;
    }

    // Print the queue
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Access the front of the queue
    T front(){
        if(empty()){
            cout<<"Can't access front. Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    // Access the rear of the queue
    T rear(){
        if(empty()){
            cout<<"Can't access rear. Queue is empty"<<endl;
            return -1;
        }
        return tail->data;
    }
    // Enqueue
    // Push the element at the rear of the queue
    void push(T data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = nullptr;
        if(empty()){
            // For the first element of the queue
            // head and tail will point to the first element
            head = newnode;
            tail = newnode; 
            ++count;
            return;
        }
        /*
        Here I'm using tail pointer to insert the element at the rear of the queue.
        Thus, we don't need to traverse the whole queue to insert the element at the rear.
        This will reduce the time complexity of the enqueue operation from O(n) to O(1).
        This optimization can be done in Linked List too.
        */
        tail->next = newnode;
        tail = newnode;
        ++count;
    }

    // Dequeue
    // delete the front element of the queue
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --count;
    }

    // delete all the elements of the queue
    void clear(){
        if(empty()){
            cout<<"queue is already empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            Node* temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // return size of the queue
    int size(){
        return count;
    }
};

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.print();
    cout<<"Size of the queue: "<<q.size()<<endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;
    return 0;
}

// This Stack is implented with the help of linked list
#include <iostream>
using namespace std;
#define endl "\n"

template <typename T>
class stack{
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
    int count;

    public:
    stack() : head(nullptr), count(0) {} // Constructor

    // Print the stack
    void print(){
        if(empty()){
            throw underflow_error("Stack is empty");
        }
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    // Push the element at the top of the stack
    void push(T data){
        Node *newnode = new Node;
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        ++count;
        return;
    }
    // Return the top element of the stack
    T top(){
        if(empty()){
            throw underflow_error("Stack is empty");
        }
        return head->data;
    }

    // Remove the top element of the stack
    void pop(){
        if(empty()){
            throw underflow_error("Stack is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --count;
    }

    // Check if the stack is empty
    bool empty(){
        return head == nullptr;
    }

    // Return the number of elements in the stack
    int size(){
        if(empty()) throw "Stack is empty";
        return count;
    }

    // Delete all the elements of the stack
    void clear(){
        Node* temp = head;
        while(temp != nullptr){
            Node* temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        head = nullptr;
        count = 0;
    }
};

int main(){
    stack<int> s;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.push(x);
    }

    cout << "The stack is: ";
    s.print();
    cout << "The top element is: " << s.top() << endl;
    s.pop();
    cout << "After popping the top element, the stack is: ";
    s.print();
    cout << "The number of elements in the stack is: " << s.size() << endl;
    return 0;
}

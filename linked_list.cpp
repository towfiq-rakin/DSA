#include<iostream>
#include <vector>
using namespace std;
#define endl "\n"

template <typename T>
class list{
    struct Node{
        T data;
        Node* next;
    };
    Node* head; // head of the list
    int count; // size of the list

    public:
    list() : head(nullptr), count(0) {} // Constructor

    // Print the list
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Push the element at the front of the list
    void pushfront(T data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        ++count;
    }

    // Insert the element after a desired node
    // data is the node after which the element is to be inserted
    void insert(T data, T num){
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* newnode = new Node;
        newnode->data = num;
        newnode->next = nullptr;
        Node* prev = head;

        while(prev->data != data){
            prev = prev->next;
            if(prev == nullptr){
                cout<<"Invalid Data"<<endl;
                return;
            }
        }
        newnode->next = prev->next;
        prev->next = newnode;
        ++count;
    }

    // Push the element at the back of the list
    void pushback(T data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = nullptr;
        if(empty()){
            head = newnode;
            ++count;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
        ++count;
    }

    // delete the first element of the list
    void popfront(){
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --count;
    }

    // delete the last element of the list
    void popback(){
        Node* temp = head;
        if(temp->next == nullptr){
            head = nullptr;
            delete temp;
            --count;
            return;

        }
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        --count;
    }

    // delete a desired element from the list
    void erase(T value){
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        if(value == temp->data){
            head = head->next;
            delete temp;
            --count;
            return;
        }

        while(temp->next->data != value){
            temp = temp->next;
            if(temp->next == nullptr){
                cout <<"Invalid Index"<<endl;
                return;
            }
        }
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        --count;
    }
    // delete all the elements of the list
    void clear(){
        if(empty()){
            cout<<"List is already empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            Node* temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        head = nullptr;
        count = 0;
    }
    // return size of the list
    int size(){
        return count;
    }
    
    // Check if the list is empty
    bool empty(){
        return head == nullptr;
    }
};
int main(){
    list<double> l;
    int n;
    cout << "Enter the size of list: ";
    cin >> n;
    cout << "Enter the elements: ";
    while(n--){
        double x;
        cin >> x;
        l.pushback(x);
    }
    cout << "The list is: ";
    l.print();
    l.insert(1, 3);
    cout << "The list after deleting the element: ";
    l.print();
    cout << "The size of the list is: " << l.size() << endl;

    
    return 0;
}

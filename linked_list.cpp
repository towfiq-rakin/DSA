#include<iostream>
using namespace std;
#define endl "\n"

template <typename T>
class list{
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
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

    // Insert the element at the given position
    void insert(T data, int pos){
        Node* newnode = new Node;
        newnode->data = data;
        if(pos == 0){
            newnode->next = head;
            head = newnode;
            ++count;
            return;
        }
        Node* temp = head;
        pos--;
        while(pos--){
            temp = temp->next;
            if(temp == nullptr){
                cout<<"Invalid Index"<<endl;
                return;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
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

    // delete the element at the given position
    void erase(int pos){
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        if(pos == 0){
            head = head->next;
            delete temp;
            --count;
            return;
        }
        pos--;
        while(pos--){
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
    cout << "The size of the list is: " << l.size() << endl;

    
    return 0;
}

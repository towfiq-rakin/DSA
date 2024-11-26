/* Description: This program implements stack using array. 
The stack is a linear data structure which follows the LIFO (Last In First Out) principle. 
The program uses a template class to implement the stack. 
NB- This stack is not dynamically sized on runtime. It has a fixed size*/

#include <iostream>
using namespace std;
#define endl "\n"

template <typename T>

// Class of the stack
class stack
{
    T mystack[100]; // array to store the elements of the stack
    int top; // top of the stack
    int maxsize; // maximum size of the stack
    
    public:
    stack(int size = 100) : top(0), maxsize(size) {} // Constructor
    ~stack() {} // Destructor
    bool empty(){
        return (top == 0); // Return true if the stack is empty
    }
    bool full(){
        return (top == maxsize); // Return true if the stack is full
    }

    void push(T element){
        if(full()){
            cout<<"Stack is full"<<endl;
            return;
        }
        // Insert the element at the top of the stac
        mystack[top++] = element; 
    }
    
    void pop(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        --top; // Remove the top element of the stack
    }

    T top_element(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        // Return the top element of the stack
        return mystack[top-1]; 
    }

    void print(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i = 0; i < top; i++){
            cout<<mystack[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.print();
}

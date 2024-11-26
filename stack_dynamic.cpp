/*This code implements stack using array 
and almost similar like a usual fixed sized array.
The only difference is, it can dynamically increase it's 
size if the stack is full*/

#include <iostream>
using namespace std;
#define endl "\n"

template <typename T>
// Class of the stack
class stack
{
    T *mystack; // array to store the elements of the stack
    int top; // top of the stack
    int maxsize; // maximum size of the stack
    
    public:
    stack(int size = 100) : top(0), maxsize(size), mystack(new T[maxsize]) {} // Constructor
    ~stack() {} // Destructor
    bool empty(){
        return (top == 0); // Return true if the stack is empty
    }
    bool full(){
        return (top == maxsize); // Return true if the stack is full
    }

    void resize(int size = 100){
        T *temp = new T[maxsize + size]; // Create a new array of double size
        for(int i = 0; i < maxsize; i++){
            temp[i] = mystack[i]; // Copy the elements of the old array to the new array
        }
        delete[] mystack; // Delete the old array
        mystack = temp; // Assign the new array to the old array
        maxsize += size; // Update the maximum size of the stack
    }
    void push(T element){
        if(full()) resize(); // Resize the stack if it is full
        
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

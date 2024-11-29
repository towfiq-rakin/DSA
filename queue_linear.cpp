/* Description: This program implements queue using array. 
The queue is a linear data structure which follows the FIFO (First In First Out) principle. 
The program uses a template class to implement the queue. 
NB- This queue is not dynamically sized on runtime. It has a fixed size.*/

#include <iostream>
using namespace std;
#define endl "\n"

// Class of the queue
template <typename T>
class queue
{
    T myqueue[100]; // array to store the elements of the queue
    int rear; // rear index of the queue
    int front; // front index of the queue
    int maxsize; // maximum size of the queue
    
    public:
    queue(int size = 100) : front(-1), rear(-1), maxsize(size) {} // Constructor

    bool empty(){
        return (front == -1 && rear == -1); // Return true if the queue is empty
    }
    bool full(){
        return (rear == maxsize-1); // Return true if the queue is full
    }

    // Push element at the rear of the queue
    void enqueue(T newelement){
        if(full()){
            cout<<"Queue is full. Enqueue error."<<endl;
            return;
        }
        if(empty()){
            front = rear = 0;
        }
        // Insert the element at the rear of the queue
        myqueue[rear++] = newelement; 
    }
    void dequeue(){
        if(empty()){
        cout<<"Queue is empty. Dequeue error."<<endl;
            return;
        }
        if((front == rear) && (front != -1)){
            front = rear = -1;
            return;
        }
        ++front; // Remove the front element of the queue
    }

    T frontElement(){
        if(empty()){
            cout<<"Queue is empty. No Front element"<<endl;
            return -1;
        }
        // Return the top element of the queue
        return myqueue[front]; 
    }

    void print(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i = front; i < rear; i++){
            cout<<myqueue[i]<<" ";
        }
        cout<<endl;
    }

    int size(){
        return rear-front; // Return the size of the queue
    }
};

int main(){
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    cout<<"Front element: "<< q.frontElement() << endl;
    q.print();
    return 0;
}

/* Circular Queue implementation using array.
Unlike linear Queue, Circular queue can
reuse it's unallocated memory which makes it efficient */

#include <iostream>
using namespace std;
#define endl "\n"

template <typename T>
class queue
{
    //int myqueue[100]
    T myqueue[100]; // array to store the elements of the queue
    int front; // front index of the queue
    int rear; // rear index of the queue
    int maxsize; // maximum size of the queue
    
    public:
    queue(int size = 5) : front(-1), rear(-1), maxsize(size) {} // Constructor

    bool empty(){
        return (front == -1 && rear == -1); // Return true if the queue is empty
    }
    bool full(){
        return ((rear+1) % maxsize == front); // Return true if the queue is full
    }

    // Push element at the rear of the queue
    void enqueue(T newelement){
        if(full()){
            cout<<"Queue is full. Enqueue Error"<<endl;
        }
        else if(empty()){
            front = rear = 0;
            myqueue[rear] = newelement;
        }
        else{
            rear = (rear+1) % maxsize;
            myqueue[rear] = newelement;
        }
        return;
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
        front = (front+1) % maxsize; // Remove the front element of the queue
    }

    T frontElement(){
        if(empty()){
            cout<<"Queue is empty. No Front element."<<endl;
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
        if(front <= rear){
            for(int i = front; i <= rear; i++){
                cout<<myqueue[i]<<" ";
            }
        }
        else{
            for(int i = front; i < maxsize; i++){
                cout<<myqueue[i]<<" ";
            }
            for(int i = 0; i <= rear; i++){
                cout<<myqueue[i]<<" ";
            }
        }
        cout<<endl;
    }
};

int main(){
    queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.enqueue(6);

    q.print();
}

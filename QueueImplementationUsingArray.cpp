/* This program implements a Queue data structure using an array. */

#include <iostream>
using namespace std;
#define MAX_LEN 50
class queue{
public:
    int a[MAX_LEN];
    int front;
    int rear;
    queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        if(front == -1 && rear == -1) return true;
        return false;
    }

    bool isFull() {
        if(rear == MAX_LEN-1) return true;
        return false;
    }

    int peek() {//returns the front of the queue
        return a[front];
    }

    void enqueue(int val) {
        if(isFull()) return;
        if(isEmpty()) {
            front = rear = 0;  
        } else { 
            ++rear;
        }
        a[rear] = val;
    }

    int dequeue() {
        int val = peek();
        if(front <= rear){
            front++;
            return val;
        }
        return -1;
    }
};


int main() {
    queue q;
    int val, res, choice = 0;
    while(choice !=-1){
        cout << "\nSelect Enqueue(1) or Dequeue(2):\n";
        cin >> choice;
        switch(choice){
            case 1: cout << "Enter the value\n";
                    cin >> val;
                    q.enqueue(val);
                    break;
            case 2: res = q.dequeue();
                    if(res!=-1) cout << "The value dequeued is:" << res;
                    else cout << "The Queue is Empty!\n";
                    break;
            default: "Try again";
                      break;
        }
    }
    return 0;
}
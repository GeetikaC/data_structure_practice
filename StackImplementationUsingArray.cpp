/* This program implements a simple stack LIFO structure using a fixed length array */

#include <iostream>
using namespace std;

#define MAX_LENGTH 100

class arrStack {
    int a[MAX_LENGTH];
    int nElem, nNum, nTop;
public:
    arrStack(){nTop=-1;}
    void push(int nElem);
    int pop();
    int top();
    bool isEmpty();

};

void arrStack::push(int nElem) {
    if(nTop==(MAX_LENGTH-1)) return;       
    a[++nTop] = nElem;
}

int arrStack::pop() {
    if(nTop == -1) return -1;
    return a[nTop--];
}

int arrStack::top() {
    if(nTop == -1) return -1;
    return a[nTop];
}

bool arrStack::isEmpty() {
    if(nTop == -1) return true;
    return false;
}

int main(){
    arrStack obj;
    int nNum, nElem, nChoice, nRes;
    while(nChoice!=-1){
        cout << "\nEnter choice: Push(1), Pop(2), EmptyCheck(3), Top(4): ";
        cin >> nChoice;
        switch(nChoice){
        case 1: 
            cout << "Enter no. of elements:\n";
            cin >> nNum;
            for ( int i=0; i<nNum; i++) {
                cout << "Enter element\n";
                cin >> nElem; 
                obj.push(nElem);
                cout << "Element at top is: " << obj.top() <<"\n";
            }
            break;
        case 2:
            nRes = obj.pop();
            if(nRes==-1) {
                cout << "Empty Stack!!";
                continue;
            }
            cout << "Element popped out: " << nRes;
            break;
        case 3:
            nRes = obj.isEmpty();
            if(nRes==1) {
                cout << "Empty Stack!!";
                continue;
            }
            cout << "Not Empty!";
            break;
        case 4:
            nRes = obj.top();
            if(nRes==-1){
                cout << "Empty Stack!!";
                continue;
            } 
            cout << nRes;
            break;
        default:
            cout << "Try again";
            break;
        }
    }
   return 0; 
}

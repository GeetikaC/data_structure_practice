/* This program implements a simple stack LIFO structure using a Linked list */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
};

void push(int nVal, Node **header){
    Node *newNode = new Node();
    newNode->data = nVal;
    if(*header == NULL){
        *header = newNode;//if list empty point to new node
        return;
    }
    newNode->next = *header;//point new node to header's next
    *header = newNode;//point header to new node
}

Node* pop(Node **header){
    Node *deleteNode = new Node();
    if(*header == NULL) return NULL;
    deleteNode = *header;
    *header = (*header)->next;//point to next node as head
    return deleteNode;//return node that will be popped out
}

bool isEmpty(Node *header){
    if(header == NULL) return true;
    return false;
}

int top(Node *header){
    if(header == NULL) return -1;
    return header->data;
}

int main() {
    Node *headPtr = new Node();
    Node *temp = new Node();
    headPtr = NULL;
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
                push(nElem, &headPtr);
                cout << "Element at top is: " << top(headPtr) <<"\n";
            }
            break;
        case 2:
            temp = pop(&headPtr);
            if(temp==NULL) {
                cout << "Empty Stack!!";
                continue;
            }
            cout << "Element popped out: " << temp->data;
            delete temp;//free memory for element popped out
            break;
        case 3:
            nRes = isEmpty(headPtr);
            if(nRes==1) {
                cout << "Empty Stack!!";
                continue;
            }
            cout << "Not Empty!";
            break;
        case 4:
            nRes = top(headPtr);
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
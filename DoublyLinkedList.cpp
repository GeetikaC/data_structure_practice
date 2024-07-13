#include <iostream>
using namespace std;

class Node {
    public:   
    int data;
    Node *next;
    Node *prev;
    Node(){
     data = 0;
     next = NULL;
     prev = NULL;   
    }
    ~Node() {;}
};

void printList(Node *head) {
    cout << "Forward List:\n";
    while(head != NULL){
        //if(head == NULL) return;
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void printListInReverse(Node *head) {
    cout << "Backward List:\n";
    if(head == NULL) return;
    while(head->next!=NULL)
        head = head->next;//goto the last node
    while(head!=NULL){//print from last to first node
        cout << head->data << " ";
        head = head->prev;
    }
    cout << "\n";
}

void insertAtHeadOfList(Node **head, int nElement) {
    Node *newNode = new Node();
    newNode->data = nElement;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTailOfList(Node **head, int nElement) {
    Node *newNode = new Node();
    Node *lastNode = new Node();
    lastNode = *head;
    newNode->data = nElement;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    while(lastNode->next!=NULL)//we dont want to reset what head pointer points to since its our only reference to the list, so we use a temp var lastNode
        lastNode = lastNode->next;//goto last node
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

int main() {
    Node *headPtr = new Node();
    headPtr = NULL;
    int nNoOfElems, nElem, nWhere;
    cout << "Enter no. of elements:\n";
    cin >> nNoOfElems;
    cout << "Head(1) or tails(2)?\n";
    cin >> nWhere;
    switch(nWhere) {
        case 1: 
        for(int i=0; i<nNoOfElems; i++) {
            cout << "Enter element:\n";
            cin >> nElem;
            insertAtHeadOfList(&headPtr, nElem);
        }
        break;
        case 2: 
        for(int i=0; i<nNoOfElems; i++) {
            cout << "Enter element:\n";
            cin >> nElem;
            insertAtTailOfList(&headPtr, nElem);
        }
        break;
    }
    printList(headPtr);
    printListInReverse(headPtr);
}

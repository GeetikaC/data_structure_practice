/* This program implements a queue data structure using a linked list. */

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
};
Node *head = new Node();
Node *rear = new Node();

bool isEmpty() {
    if(head == NULL && rear == NULL) return true;
    return false;
}

int peek() {
    if(head!=NULL) return head->data;
    return -1;
}

void enqueue(int val) {
    Node *newNode = new Node();
    newNode->data = val;
    if(isEmpty()){
        head = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if(isEmpty()) return -1;
    int val = peek();
    Node *deleteNode = head;
    head = head->next;
    if(head==NULL) rear = NULL; //the list is empty
    delete deleteNode;
    return val;
}

void printList() {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int val, res, choice = 0;
    head = NULL;
    rear = NULL;
    while(choice != -1){
        cout << "\nEnter your selection (1)Enqueue (2)Dequeue: \n";
        cin >> choice;
        switch(choice){
            case 1: cout << "Enter the value: ";
                    cin >> val;
                    enqueue(val);
                    cout << "The list now is: ";
                    printList();
                    break;
            case 2: res = dequeue();
                    if(res!=-1) {
                        cout << "The value removed is: " << res << "\n";
                        cout << "The list now is: ";
                        printList();
                    }
                    else cout << "List is Empty!";
                    break;
            default: cout << "Invalid choice..try again.";
                     break;
        }
    }
    return 0;
}
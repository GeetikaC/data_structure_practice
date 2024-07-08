#include <iostream>
#include <string>
/*  This program implements reversing a linked list in reverse using recursion. 
This is going to change the linked list elements original order and going to display them in 
reverse order.
*/
using namespace std;
int nElementsCount=1;
class Node {
    int data;
    public:
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
    void setData(int value) { data = value; };
    int getData(){ return data; };
};

void insertIntoList(Node **header, int num, int pos) {
    //check if npos is valid within range of 0-numOfElements
    //take n-1th node and point n to its next
    //point n-1 to n
    Node *tempNode = new Node();//node to be inserted
    Node *tempNode2 = new Node();//node prev to it
    tempNode->setData(num);
    tempNode->next = NULL;
    tempNode2->next = *header;
    if(pos == 0 && *header!=NULL) {
        tempNode->next = *header;
        *header = tempNode;
    } else if(pos>0 && *header!=NULL) {
        for(int i=0; i<pos; i++){
            tempNode2 = tempNode2->next;//tempNode2 points to n-1 node
        }
        tempNode->next = tempNode2->next;
        tempNode2->next = tempNode;
    } else if(*header==NULL){
        *header = tempNode;
    }
    ++nElementsCount;
}

Node *reverseList(Node *nextNode) {//using recursion we are performing a last node to first node traversal after end node is reached i.e. node pointing to NULL
    static Node *headerVal = new Node();
    Node *current = new Node();
    headerVal = nextNode;
    if(nextNode->next == NULL) {
        headerVal = nextNode;//point header to last node to make it first node in reversed list.
        return headerVal;
    }
    reverseList(nextNode->next);//gets recursively called for the whole of the list until it reaches last node
    current = nextNode->next;
    current->next = nextNode;
    nextNode->next = NULL;
    return headerVal;
}

void printList(Node *header) { //using recursion
    while(header != NULL){
        cout << header->getData() <<" ";//prints the value of each node
        header = header->next;
    }
}

int main()
{
    Node *header = new Node();
    header = NULL;
    int nNumber, nPos, nDeletePos;
    while(nNumber!=-1) {
        cout << "\nEnter the element: \n";
        cin >> nNumber;
        cout << "Enter where to insert the element: \n";
        cin >> nPos;
        if(nPos>=0 && nPos<nElementsCount) {
            insertIntoList(&header, nNumber, nPos); 
        }
    }
    cout << "The List in order:\n";
    printList(header);
    cout << "Reversed List:\n";
    header = reverseList(header);
    printList(header);
    return 0;
}
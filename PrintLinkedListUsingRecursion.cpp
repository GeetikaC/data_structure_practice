#include <iostream>
#include <string>
/*  This program implements printing a linked list in order and in reverse using recursion. 
This is not going to change the linked list elements original order in any way, it is just 
going to display them in reverse and straight orders.
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

void reverseList(Node *header) {//using recursion
    if(header == NULL) return;
    reverseList(header->next);//gets recursively called for the whole of the list until it reaches last node
    cout << header->getData() <<" ";//when header=NULL i.e. last node, it print the value of the node and goes to next call in the stack for printing n-1th node, and so on
}

void printList(Node *header) { //using recursion
    if(header == NULL) return;
    cout << header->getData() <<" ";//prints the value of each node
    printList(header->next);//then recursively calls itself to point to next node and so on
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
    reverseList(header);
    return 0;
}
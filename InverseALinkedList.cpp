#include <iostream>
#include <string>
/*  This program implements reversing a linked list.
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

void reverseList(Node **header, int count) {
    Node *tempCurrentNode = new Node();
    Node *tempPrevNode = new Node();
    Node *tempNextNode = new Node();
    tempCurrentNode = *header;//current points to the head node, pointing to first element of the list. We iterate over the list using this to point to current node.
    tempPrevNode = NULL;//this node helps keep track of prev node to current node. We iterate over the list using this to point to prev node.
    tempNextNode = NULL;//this helps to increment current node to the next node for each iteration
    while(tempCurrentNode!=NULL) {
        tempNextNode = tempCurrentNode->next;//stores value of next node for current to increment to for next iteration
        tempCurrentNode->next = tempPrevNode;//links to the prev element
        tempPrevNode = tempCurrentNode;//increment the pointer of prev to point to next node
        tempCurrentNode = tempNextNode;//increment the pointer of current to point to next node
    }
    *header = tempPrevNode;//header finally points to the last node encountered, which becomes our first node of the reversed list.
}

void printList(Node * header, int count) {
    while(header!=NULL && count!=0) {
        cout << header->getData() << " ";
        header = header->next;
        --count;
    }
}

int main()
{
    Node *header = new Node();
    header = NULL;
    int nNumber, nPos, nDeletePos;
    while(nPos!=-1) {
        cout << "\nEnter the element: \n";
        cin >> nNumber;
        cout << "Enter where to insert the element: \n";
        cin >> nPos;
        if(nPos>=0 && nPos<nElementsCount) {
            insertIntoList(&header, nNumber, nPos);
            printList(header,nElementsCount);  
        }
    }
    cout << "Reversed List:\n";
    reverseList(&header,nElementsCount);
    printList(header,nElementsCount);
    return 0;
}
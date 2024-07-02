#include <iostream>
#include <string>
/*  This program implements a linked list with values inserted 
    at the nth position of the list.
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

void deleteFromList(Node **header, int npos) {
    Node *tempDeleteNode = new Node();//node prev to it
    Node *tempPrevNode = new Node();//node prev to it
    tempPrevNode->next = *header;
    tempDeleteNode = *header;
    if(npos == 0) {
        *header = tempDeleteNode->next;//header now points to 1st node and not 0th
        delete tempDeleteNode;
        --nElementsCount;
        return;
    }
    for(int i=0; i<npos; i++) {
        tempPrevNode = tempPrevNode->next;//points to node prev to one being deleted
    }
    if(tempPrevNode->next!=NULL) {
        tempDeleteNode = tempPrevNode->next;
        tempPrevNode->next = tempDeleteNode->next;//point prev node to node after deleted node
        delete tempDeleteNode;
    } else {
        cout << "Invalid entry...doesnt exist";
    }
    --nElementsCount;
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
        } else {
            cout << "Invalid input. Try again.\n";
        }
    }
    while(nElementsCount>0 && header!=NULL) {
        cout << "Enter the position to be deleted:\n";
        cin >> nDeletePos;
        deleteFromList(&header,nDeletePos);
        printList(header,nElementsCount);  
    }
    cout << "List is empty.";
    return 0;
}
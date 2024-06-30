#include <iostream>
#include <string>
/*  This program implements a linked list with values inserted 
    at the beginnning of the list.
*/
using namespace std;

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

void insertIntoList(Node** header, int num){
    Node *tempNode = new Node();
    tempNode->setData(num);
    if(header!=NULL) {
        tempNode->next = *header;
    }
    *header = tempNode;
}

void printList(Node * header, int count){
    while(header!=NULL && count!=0){
        cout << header->getData();
        header = header->next;
        count--;
    }
}

int main()
{
    int nElements, nNumber;
    Node *header = new Node();
    cout << "Enter Number of elements:\n";
    cin >> nElements;
    for(int i=0; i<nElements; i++){
        cout << "Enter the element: ";
        cin >> nNumber;
        insertIntoList(&header, nNumber);
    }
    printList(header,nElements);     
    return 0;
}
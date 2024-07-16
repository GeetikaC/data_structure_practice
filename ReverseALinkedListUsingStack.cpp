#include <iostream>
#include <string>
#include <stack>
/*  This program implements reversing a linked list using stack.
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

void reverseTheList(Node **head){
    if(*head == NULL) return;//Empty list
    Node *temp = new Node();
    temp = *head;
    stack<Node*> st;
    while(temp != NULL){ //push into the stack
        st.push(temp);
        temp = temp->next;
    }
    temp = st.top();//Last node becomes head
    *head = temp;
    st.pop();
    while(!st.empty()){
        temp->next = st.top();
        st.pop();//pop out the node
        temp = temp->next;//next node
    }
    temp->next = NULL;//last element point to NULL
}

int main()
{
    int nElements, nNumber;
    Node *header = new Node();
    header = NULL;
    cout << "Enter Number of elements:\n";
    cin >> nElements;
    for(int i=0; i<nElements; i++){
        cout << "Enter the element: ";
        cin >> nNumber;
        insertIntoList(&header, nNumber);
    }
    printList(header,nElements);    
    reverseTheList(&header);
    cout << "\nReversed List: ";
    printList(header,nElements);
    return 0;
}
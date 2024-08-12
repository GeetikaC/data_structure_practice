/* This program implements level order traversal and depth first traversal including Preorder, Inorder, Postorder
 traversal of the binary tree */
#include <iostream>
#include <queue>
using namespace std;
#define COUNT 10
class binaryTree{
    public:
    int data;
    binaryTree *leftSubtree;
    binaryTree *rightSubtree;
    binaryTree(){ //constructor
        data = 0;
        leftSubtree = NULL;
        rightSubtree = NULL;
    }
};

binaryTree *createNode(int val){
    binaryTree *newNode = new binaryTree();
    newNode->data = val;
    return newNode;
}

void insertNode(binaryTree **Node, int val){
    if(*Node == NULL){ //if tree is empty
       *Node = createNode(val);
       return; 
    }
    if(val>(*Node)->data){ //if val is greater than root node value
        insertNode(&(*Node)->rightSubtree, val);
    } else {//if val is lesser than root node value
        insertNode(&(*Node)->leftSubtree, val);
    }
}

void removeNode(binaryTree **Node, int val){
    if(*Node == NULL) return; //tree is empty
    else if(val == (*Node)->data) {
        binaryTree *deleteNode = *Node;
        *Node = NULL;//make the node point to NULL
        delete deleteNode; 
        return;
    }
    else if(val > (*Node)->data) removeNode(&(*Node)->rightSubtree, val);
    else removeNode(&(*Node)->leftSubtree, val);
}

bool searchNode(binaryTree **Node, int val){
    if(*Node == NULL) return false; //tree is empty
    else if(val == (*Node)->data) return true; //root node is the value
    else if(val > (*Node)->data) return searchNode(&(*Node)->rightSubtree, val);//if val is greater than root node value
    else return searchNode(&(*Node)->leftSubtree, val);//if val is lesser than root node value
}

void printTree(binaryTree *Node, int space){
    if (Node == NULL) return;//tree is empty
    space += COUNT;
    printTree(Node->rightSubtree, space);//prints the rightmost node first
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << Node->data << "\n";//prints the current root node of the rightmost node
    printTree(Node->leftSubtree, space);//prints left node of current node
}

void levelOrderTraversalPrint(binaryTree *Node){
    if (Node == NULL) return;//tree is empty
    queue<binaryTree*> tempStore;
    binaryTree* topNode = new binaryTree();
    tempStore.push(Node);
    while(!tempStore.empty()){ //queue will be empty only on completing the traversal
        topNode = tempStore.front();
        cout << topNode->data << " ";
        if(topNode->leftSubtree!=NULL) tempStore.push(topNode->leftSubtree);
        if(topNode->rightSubtree!=NULL) tempStore.push(topNode->rightSubtree);
        tempStore.pop();//to remove the already visited/printed node
    }
}

void preorderTraversalPrint(binaryTree *Node){
    if (Node == NULL) return;//tree is empty
    cout << Node->data << " ";
    preorderTraversalPrint(Node->leftSubtree);
    preorderTraversalPrint(Node->rightSubtree);
}

void postorderTraversalPrint(binaryTree *Node){
    if (Node == NULL) return;//tree is empty
    postorderTraversalPrint(Node->leftSubtree);
    postorderTraversalPrint(Node->rightSubtree);
    cout << Node->data << " ";
}

void inorderTraversalPrint(binaryTree *Node){
    if (Node == NULL) return;//tree is empty
    inorderTraversalPrint(Node->leftSubtree);
    cout << Node->data << " ";
    inorderTraversalPrint(Node->rightSubtree);
}

int main(){
    int nVal, nChoice=0;
    binaryTree *rootPtr = new binaryTree();
    rootPtr = NULL;
    while(nChoice!=-1){
        cout << "\nEnter your choice (1)Insert (2)Delete (3)Search (4)Level Order (5)Preorder (6)Inorder (7)Postorder: ";
        cin >> nChoice;
        switch(nChoice){
            case 1: cout << "\nEnter the value to be inserted. ";
                    cin >> nVal;
                    insertNode(&rootPtr, nVal);
                    printTree(rootPtr, 1);
                    break;
            case 2: cout << "\nEnter the value to be deleted. ";
                    cin >> nVal;
                    removeNode(&rootPtr, nVal);
                    printTree(rootPtr, 1);
                    break;
            case 3: cout << "\nEnter the value to be searched. ";
                    cin >> nVal;
                    if(searchNode(&rootPtr, nVal)) cout << "Found it!";
                    else cout << "Not Found!";
                    break;
            case 4: levelOrderTraversalPrint(rootPtr);
                    break;
            case 5: preorderTraversalPrint(rootPtr);
                    break;
            case 6: inorderTraversalPrint(rootPtr);
                    break;
            case 7: postorderTraversalPrint(rootPtr);
                    break;
            default: cout << "\nInvalid choice..try again..";
                    break;
        }
    }
    return 0;
}
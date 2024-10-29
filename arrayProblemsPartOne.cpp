/* Some common array problems and their solutions */

#include <bits/stdc++.h>
using namespace std;

//largest element in an array
int printLargest(int a[], int n){
    int largest = a[0];
    for(int i=0; i<n; i++){
        if(largest < a[i])  largest = a[i];
    }
    return largest;
}

//second largest element in an array
int printSecondLargest(int a[], int n){
    int largest = a[0];
    int secondLargest = -1;
    for(int i=0; i<n; i++){
        if(largest < a[i])  largest = a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i] > secondLargest && a[i] < largest)  secondLargest = a[i];
    }
    return secondLargest;
}

//second largest element in an array
int printSecondLargestOPTIMISED(int a[], int n){
    int largest = a[0];
    int secondLargest = -1;
    for(int i=0; i<n; i++){
        if(largest < a[i]){
            if(secondLargest < largest)
                secondLargest = largest;
            largest = a[i];
        }
    }
    return secondLargest;
}

//second smallest element in an array
int printSecondSmallestOPTIMISED(int a[], int n){
    int smallest = a[0];
    int secondSmallest = INT_MAX;
    for(int i=0; i<n; i++){
        if(smallest > a[i]){
            if(secondSmallest > smallest)
                secondSmallest = smallest;
            smallest = a[i];
        }
    }
    return secondSmallest;
}

//check if array is sorted in ascending or not
bool isSorted(int a[], int n){
    bool res = true;
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]) res = false;
    }
    return res;
}

//in a sorted array with duplicates find and place unique elements at the front and return number of unique elements found
void printUnique(int a[], int n){
    int totalUniq = 1;
    for(int i=1; i<n-1; i++){
        if(a[i] != a[i+1]){
            a[totalUniq] = a[i+1];
            totalUniq++;
        }
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\nTotal Unique: " << totalUniq;
}

//All elements of the array shift one place to the left and the leftmost becomes rightmost element, almost like its a circular array.
void leftRotate(int a[], int n){
	int leftmostElem = a[0];
	for(int i=1; i<n; i++){
		a[i-1] = a[i];
	}
	a[n-1] = leftmostElem;
    for(int i=0; i<n; i++){ // printing resulting array
        cout << a[i] << " ";
    }
}

void leftRotateByMPlaces(int a[], int n, int m){
    m = m % n; //for any rotations m>=n we have to perform m%n rotations to get correct more efficient rotation, exact rotation number gives same result 
    int leftmostElems[m];
    for(int i=0; i<m; i++){//store elements which will be shifted to rightmost indices into a temp array
        leftmostElems[i] = a[i];
    }
	for(int i=m; i<n; i++){//start shifting from m till length of array
		a[i-m] = a[i];
	}
    for(int i=n-m; i<n; i++){//place the leftmost values BACK into the original array
        a[i] = leftmostElems[i-(n-m)];
    }
    for(int i=0; i<n; i++){ // printing resulting array
        cout << a[i] << " ";
    }
}

void doReverse(int a[], int start, int end){
    while(start<end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void leftRotateByMPlacesOPTIMISED(int a[], int n, int m){//not making use of the extra temp array leftmostElems[]
    m = m % n; //for any rotations m>=n we have to perform m%n rotations to get correct more efficient rotation, exact rotation number gives same result 
    doReverse(a, 0, m-1); //revrse first m elements
    doReverse(a, m, n-1);//reverse the elements from m to n
    doReverse(a, 0, n-1);//reverse the whole array   
    for(int i=0; i<n; i++){ // printing resulting array
        cout << a[i] << " ";
    } 
}

//Move all zeroes to the end of the array
void moveZeroesToEnd(int a[], int n){
    int i = -1;
    int j = -1;
    for(int x=0; x<n; x++){//finds first 0 in the array to init i and j
        if(a[x]==0){
            i = x;
            j = x+1;
            break;
        }
    }
    if(i == -1)	 return; //if array contains no 0
    while(i<n && j<n){//when j crosses arrays size, the arrays zeroes are bubbled to the end
        if(a[j] !=0){//swap i & j if i is 0 and j is non 0
            swap(a[i], a[j]);
            i++;
            j++;
        } else {//if j is 0 we incr to get next non 0
            j++;
        }
    }
    for(int i=0; i<n; i++){ // printing resulting array
        cout << a[i] << " ";
    }
}

//We compare all elements of the array with the num and if found, we return the index, else we return -1
int linearSearch(int a[], int n, int val){
    for(int i=0; i<n; i++){
        if(a[i] == val) return i;
    }
    return -1;
}

//we take each element of both arrays and push it into the set. The set stores unique elements in a sorted order.
void printUnion(int a[], int n){
    int m;
    cout << "Enter the size of the second array: ";
    cin >> m;
    int b[m];
    cout << "Enter the values: ";
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout << "The union is: ";
    set<int> st;    
    for(int i=0; i<n; i++){//storing a into set
        st.insert(a[i]);
    }
    for(int j=0; j<m; j++){//storing b into set
        st.insert(b[j]);
    }
    int result[st.size()];
    int x=0;
    for(auto setElem : st){ //storing into result array from set
        result[x++] = setElem;
    }
    for(int i=0; i<x; i++){ // printing resulting array
        cout << result[i] << " ";
    }
}

//using two pointer approach. The inuput arrays are sorted.
void printUnionOPTIMISED(int a[], int n){
    int m;
    cout << "Enter the size of the second array: ";
    cin >> m;
    int b[m];
    cout << "Enter the values: ";
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout << "The union is: ";
    vector<int> res;
    int i = 0;//to iterate over array a
    int j = 0;//to iterate over array b

    while(i<n && j<m){ //check whichever element is smaller in the two arrays and not already present in the result array is inserted
        if(a[i]<=b[j]) {
            if(res.empty() || a[i]!=res.back()){
                res.push_back(a[i]);
            }
            i++;
        } else {
            if(res.empty() || b[j]!=res.back()){
                res.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n){//if array b is exhausted but a is still left
        if(res.empty() || a[i]!=res.back()){
            res.push_back(a[i]);
        }
        i++;
    }
    while(j<m){//if array a is exhausted but b is still left
        if(res.empty() || b[j]!=res.back()){
            res.push_back(b[j]);
        }
        j++;
    }
    for(int p=0; p<res.size(); p++){ // printing resulting array
        cout << res.at(p) << " ";
    }
}

//the common elements in the given two arrays, repetition in resulting array is allowed if each pair of the elements equivalent exists.
void printIntersection(int a[], int n){
    int m;
    cout << "Enter the size of the second array: ";
    cin >> m;
    int b[m];
    cout << "Enter the values: ";
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout << "The intersection is: ";
    vector<int> res;
    int visited[m] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == b[j] && visited[j] == 0)
            {
                res.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if(b[j]>a[i]){//if the element in b is greater than a, since its a sorted array, we know the rest of the values are not to be checked.
                break;
            }
        }
    }
    for(int p=0; p<res.size(); p++){ // printing resulting array
        cout << res.at(p) << " ";
    }
}

//using two pointer approach. The inuput arrays are sorted.
void printIntersectionOPTIMISED(int a[], int n){
    int m;
    cout << "Enter the size of the second array: ";
    cin >> m;
    int b[m];
    cout << "Enter the values: ";
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout << "The Intersection is: ";
    vector<int> res;
    int i = 0;//to iterate over array a
    int j = 0;//to iterate over array b

    while(i<n && j<m){ //check whichever element is smaller in the two arrays and not already present in the result array is inserted
        if(a[i]==b[j]) {
            res.push_back(a[i]);
            i++;
            j++;
        } else if(a[i] < b[j]){
            i++;
        } else {
            j++;
        }
    }
    
    for(int p=0; p<res.size(); p++){ // printing resulting array
        cout << res.at(p) << " ";
    }
}

int main(){
    int n, choice, m, sol;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the values: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "(1) Largest (2) Second Largest (3) Second Largest (4) Second smallest (5) isSorted (6) Total Unique (7) Left Rotate (8) Left Rotate by M places\n (9) Left Rotate by M places OPTIMISED (10) Place all zeroes to array end (11) Linear Search (12) Print Union (13) Print Intersection\n";
    cin >> choice;
    switch(choice){
        case 1: cout << "Largest: " << printLargest(a, n);
                break;
        case 2: cout << "Second Largest: " << printSecondLargest(a, n);
                break;
        case 3: cout << "Second Largest: " << printSecondLargestOPTIMISED(a, n);
                break;
        case 4: cout << "Second smallest: " << printSecondSmallestOPTIMISED(a, n);
                break;
        case 5: if(isSorted(a, n))  cout << "Sorted!!";
                else cout << "Not sorted!!\n";
                break;
        case 6: printUnique(a, n);
                break;
        case 7: leftRotate(a, n);
                break;
        case 8: cout << "Enter number of places to rotate by: \n";
                cin >> m;
                leftRotateByMPlaces(a, n, m);
                break;
        case 9: cout << "Enter number of places to rotate by: \n";
                cin >> m;
                leftRotateByMPlacesOPTIMISED(a, n, m);
                break;
        case 10: moveZeroesToEnd(a, n);
                 break;
        case 11: cout << "Enter number to be searched: \n";
                cin >> m; 
                sol = linearSearch(a, n, m);
                if(sol>=0) cout << "Element found at index "<< sol;
                else cout << "Element not found";
                break;
        case 12: printUnionOPTIMISED(a, n);
                break;
        case 13: printIntersectionOPTIMISED(a, n);
                break;
        default: cout << "Invalid Choice.. try again.";
                break;
    }
    return 0;
}
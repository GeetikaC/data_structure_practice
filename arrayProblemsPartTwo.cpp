/* Some common array problems and their solutions */

#include <bits/stdc++.h>
using namespace std;

//Find the missing number in given array of elements from 1 to m where m is given
int missingElement(int a[], int nSize, int m){
    int XOR1 = 0;//XOR of all elements from 1 to m
    int XOR2 = 0;//XOR of all elements in given array
    for(int i=0; i<nSize; i++){
        XOR2 = XOR2 ^ a[i];
        XOR1 = XOR1 ^ i+1; //elements 1,2,..m-1
    }
    XOR1 = XOR1 ^ m; //element m that was left
    return XOR1 ^ XOR2;
}

//Find the max number of times ones occur consecutively in an array
int maxConsecutiveOnes(int a[], int nSize){
    int nMaxConsecutive = 0;//to keep count of MAX of 1s found cosecutively
    int nCounter = 0;//to keep count of 1s found cosecutively
    for(int i=0; i<nSize; i++){
        if(a[i] == 1){
            nCounter++;
            nMaxConsecutive = max(nMaxConsecutive, nCounter);
        } else {
            nCounter = 0;
        }
    }
    return nMaxConsecutive;
}

//Find the number that appears only once if all other appear twice in given sorted array
int appearsOnceSortedArray(int a[], int nSize){
    int temp = a[0];//to compare elements
    int nCounter = 0;//to keep count
    for(int i=0; i<nSize; i++){
        if(temp == a[i]){
            nCounter++;
        } else {
            if(nCounter == 1) return a[i];
            temp = a[i];
            nCounter = 0;
        }
    }
    return -1;
}

//Find the number that appears only once if all other appear twice in given non-sorted array
int appearsOnceArray(int a[], int nSize){
    int res = -1;
    map <int, int> occurancesMap;
    for(int i=0; i<nSize; i++){
        occurancesMap[a[i]] += 1;
    }
    for(auto occurance : occurancesMap){
        if(occurance.second == 1)   res = occurance.first;
        else res = -1;
    }
    return res;
}

//Find the number that appears only once if all other appear twice in given non-sorted array
int appearsOnceArrayXORMethod(int a[], int nSize){
    int XOR1 = 0;
    for(int i=0; i<nSize; i++){
        XOR1 = XOR1 ^ a[i];
    }
    return XOR1;
}

//find the first subarray in given array with sum equal to the value m provided
void findSum(int a[], int n, int m){
    int summation = 0;
    int len = 0;
    int sum_Arr[n];
    int start = 0;
    bool restart = true;
    while(restart){
        for(int i=start; i<n; i++){
            summation += a[i];
            if(summation == m){//check if summation is equal to m provided
                len = i;//fetch length of the subarray and start
                restart = false;//no longer required to restart the checks
                break;
            } else if(summation > m){//if summation surpasses, we try looping again from start+1 index to n
                summation = 0;
                start++;
                restart = true;
                break;
            }
        }
    }
    for(int i=start; i<=len; i++){//prints the final subarray
        cout << a[i] <<" ";
    }
}

//Two pointer approach to find the LARGEST subarray in given array with sum equal to the value m provided
void printLongestSubarrayOfSum(int a[], int n, int m){
    int left = 0;
    int right = 0;
    int summation = 0;
    int largestSubarrStartIndx = 0;
    int largestSubarrEndIndx = 0;
    int largestLen = 0;
    while(left<n && right<n){
        summation += a[right];
        if(summation == m){
            largestLen = right-left;
            if(largestLen > largestSubarrEndIndx){
                largestSubarrEndIndx = right;
                largestSubarrStartIndx = left;
            }
        } else if(summation > m){
            summation -= a[left];
            left++;
        }
        right++;
    }
    for(int i=largestSubarrStartIndx; i<=largestSubarrEndIndx; i++){//prints the final subarray
        cout << a[i] <<" ";
    }
}

int main(){
    int n, m, choice, res;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the values: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "(1) Missing element (2) Max consecutive ones (3) Appearing once (4) Appearing once MAP METHOD (5) Appearing once XOR METHOD (6) Subarray with given sum (7) LARGEST Subarray with given sum\n";
    cin >> choice;
    switch(choice){
        case 1: cout << "\nEnter the length of the array to find missing element: ";
                cin >> m;
                cout << "Missing element: " << missingElement(a, n, m);
                break;
        case 2: cout << "Max consecutive ones: "<< maxConsecutiveOnes(a, n);
                break;
        case 3: res = appearsOnceSortedArray(a, n);
                if(res!=-1) cout << "Appearing once: "<< res;
                else cout << "Not found!";
                break;
        case 4: res = appearsOnceArray(a, n);
                if(res!=-1) cout << "Appearing once: "<< res;
                else cout << "Not found!";
                break;
        case 5: cout << "Appearing once: "<< appearsOnceArrayXORMethod(a, n);
                break;
        case 6: cout << "Subarray with given sum: ";
                findSum(a,n,4);
                break;
        case 7: cout << "Subarray with given sum: ";
                printLongestSubarrayOfSum(a,n,15);
                break;
        default: cout << "Invalid Choice.. try again.";
                break;
    }
    return 0;
}
/* Through this code some common sorting techniques are explored and implemented */

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int size){
    int temp;
    for(int i=0; i<size-1; i++){// outer loop runs to swap each index with lowest of the rest of array
        int minElem = i;
        for(int j=i; j<size-1; j++){//inner loop to find lowest of the rest of array
            if(a[j]<a[minElem])    minElem = j;
        }
        temp = a[minElem];
        a[minElem] = a[i];
        a[i] = temp;
    }
}

void bubbleSort(int a[], int size){
    bool isSwapDone = false;
    while(size!=0){
        for(int i=0; i<size-1; i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                isSwapDone = true;
            } 
        }
        if(!isSwapDone) break; //if there are no swaps done in the first iteration across the array, the array is already sorted.
        size--;
    }
}

void insertionSort(int a[], int size){
    for(int i=0; i<=size-1; i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j-1],a[j]);
            j--;
        }
    }
}

void merge(int a[], int low, int mid, int high){
    vector<int> temp;
	int left = low;
	int right = mid+1;
	while(left<=mid && right<=high){//while both left and right dont point to end of their respective halves
		if(a[left]<=a[right]){ //push the lowest of the two into temp
			temp.push_back(a[left]);
			left++;
		}else{	
			temp.push_back(a[right]);
			right++;
		}
	}
	if(left>mid){//if left array is completed, store the rest of sorted right array into temp
	while(right<=high){
		temp.push_back(a[right]);
		right++;
		}
	}
	if(right>high){//if right array is completed, store the rest of sorted left array into temp
	while(left<=mid){
		temp.push_back(a[left]);
		left++;
		}
	}
	for(int i=low; i<=high; i++){//store sorted variables in temp into original array
		a[i] = temp[i-low];
	}
}

void mergeSort(int a[], int low, int high){//a is the input array, low is pointing to start of array, high is pointing to last index of array
    if(low>=high)	return;//base condition: if the division of the array reaches singular indexes ie low == high then we need to stop
	int mid = (low+high)/2; //gives the middle_ptr pointing to the mid element.
	mergeSort(a, low, mid); //divide 1st half of array from low to mid further
	mergeSort(a,mid+1,high); //divide 2nd half of array from mid+1 to high further
	merge(a,low,mid,high);//sort and merge the elements together
}

//in quicksort, we select a pivot element and and swapping the elements to get the lower elements to the left and higher elements to the right of the pivot
int partition(int a[], int low, int high){
    int i = low;
    int j = high;
    int pivot = a[low];
    while(i<j){
        while(a[i]<=pivot && i<=high-1) i++;
        while(a[j]>pivot && j>=low+1) j--;
        if(i<j) swap(a[i],a[j]);//we only swap until i surpasses j at which case pivot position is found
    }
    swap(a[low],a[j]);
    return j;//the partition element where the pivot is stored and the left side of this is left array and right is right array, which are again pivoted and sorted
}

void quicksort(int a[], int low, int high){
    if(low <= high){
        int nPartition = partition(a,low,high);
        quicksort(a,low,nPartition-1);
        quicksort(a,nPartition+1,high);
    }
}

int main(){
    int n, choice;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the values: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "(1) Selection Sort (2) Bubble sort (3) Insertion Sort (4)Merge Sort (5)Quicksort";
    cin >> choice;
    switch(choice){
        case 1: selectionSort(a, n);
                break;
        case 2: bubbleSort(a, n);
                break;
        case 3: insertionSort(a, n);
                break;
        case 4: mergeSort(a, 0, n-1);
                break;
        case 5: quicksort(a, 0, n-1);
                break;
        default: cout << "Invalid Choice.. try again.";
                break;
    }
    cout << "Sorted Elements are: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
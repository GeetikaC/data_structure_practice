/* Through this code some common math concepts like GCD, palindrome, armstrong numbers etc are explored and implemented */
#include <bits/stdc++.h>
using namespace std;

int calcDigits(int n){ //Given an integer N, return the number of digits in N.
    int count = 0;
    while(n > 0){
        count++;
        n = n/10;
    }
    return count;
}

string printReverseUsingStr(int n){
    string str = "";
    while(n > 0){
        str += to_string(n%10);
        n = n/10;
    }
    return str;
}

int printReverseUsingInt(int n){
    int revNum = 0;
    while(n>0){
        revNum = (revNum*10) + (n%10);
        n = n/10;
    }
    return revNum;
}

void checkIfPalindrome(int n){
    int initialVal = n;
    int reverseVal = 0;
    while (n>0){
        reverseVal = (reverseVal*10) + n%10;
        n = n/10;
    }
    if(initialVal == reverseVal) cout << "True" << endl;
    else cout << "False" << endl;
}

void isArmstrongNumber(int n){
    int initialVal = n;
    int total = 0;
    while (n>0){
        total += pow(double(n%10), 3.0);
        n = n/10;
    }
    if(initialVal == total) cout << "True" << endl;
    else cout << "False" << endl;
}

void printDivisors(int n){
    for(int i=1; i<=n; i++){
        if(n%i){
            continue;
        }
        cout << i << " ";
    }
}

void printDivisorsOPTIMISED(int n){
    vector<int> v;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            v.push_back(i);//the lower divisor
            if(n/i != i) v.push_back(n/i);//the higher divisor
        }
    }
    sort(v.begin(), v.end());
    for(auto val : v)   cout << val << " ";
}

void checkIfPrime(int n){
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            count++;//the lower divisor
            if(n/i != i) count++;//the higher divisor
        }
    }
    if(count == 2) cout << "True" << endl;
    else cout << "False" << endl;
}

void findGCD(int val1, int val2){
    if(val1 !=0){
        int maxVal = max(val1, val2);
        int minVal = min(val1, val2);
        findGCD(maxVal-minVal, minVal);
    }
    else cout << val2;
    return;
}
/*instead of going thru all the steps of continuous subtraction, we can simply perform:
GCD(max_val%min_val, min_val) till we get 0 as one of the values..which gives us GCD as the other non-zero value.*/
void findGcdOPTIMISED(int val1, int val2){
    while(val1>0 && val2>0){
        if(val1>val2) val1 = val1%val2;
        else val2 = val2%val1;
    }
    if(val1 == 0) cout << val2;
    else cout << val1;
}

int main(){
    int n, choice, val1, val2;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter your choice: (1)calculateDigits (2)printReverse (3)checkIfPalindrome (4)isArmstrongNumber (5)printDivisors (6)checkIfPrime (7)findGCD";
    cin >> choice;
    switch(choice){
        case 1: cout << "The digits: " << calcDigits(n);
                break;
        case 2: cout << "The reverse: " << printReverseUsingInt(n);
                break;
        case 3: checkIfPalindrome(n);
                break;
        case 4: isArmstrongNumber(n);
                break;
        case 5: printDivisorsOPTIMISED(n);
                break;
        case 6: checkIfPrime(n);
                break;
        case 7: cout << "Enter the pair of numbers: ";
                cin >> val1 >> val2;
                findGcdOPTIMISED(val1, val2);
                break;
        default: cout << "Invalid choice..try again..";
                break;
    }
    return 0;
}
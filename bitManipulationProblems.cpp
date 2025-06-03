/* Some Bit Manipulation related problems */

#include <bits/stdc++.h>
using namespace std;


string converToBinaryFormat(int num){//convert a decimal to its binary
    string val = "";
    while(num>0){
        val.insert(val.begin(), (num%2) + '0');
        num = num/2;
    }
    return val;
}

int converToDecimalFormat(string num){
    int val = 0;
    int len = num.size()-1;
    for(int i=len; i>=0; i--){
        if(num[i] == '1'){
            val += pow(2,len-i);
        }
    }
    return val;
}


int main(){
    int nVal, nChoice;
    string res, strVal;
    cout << "Select your choice (1) Decimal to binary (2) Binary to decimal.\n";
    cin >> nChoice;
    switch(nChoice){
        case 1: cout <<"Enter the decimal to convert to binary: ";
                cin >> nVal;
                res = converToBinaryFormat(nVal);
                cout << "The binary equivalent is: "<< res;
                break;
        case 2: cout <<"Enter the binary to convert to decimal: ";
                cin >> strVal;
                cout << "The decimal equivalent is: "<< converToDecimalFormat(strVal);
                break;
        default: cout << "Enter a valid choice.";
                 break;
    }
    return 0;
}

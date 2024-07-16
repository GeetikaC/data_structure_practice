/* Using stack to reverse an input string */

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void reverseAString(char ch[]){
    stack<char> st;
    int nSize = strlen(ch);
    for(int i=0; i<nSize; i++){//loop for push
        st.push(ch[i]);
    }

    for(int i=0; i<nSize; i++){//loop for pop
        ch[i] = st.top();
        st.pop();
    }
    ch[nSize] ='\0';
}


int main() {
    char ch[50];
    cout << "Enter the string to reverse: ";
    cin >> ch;
    reverseAString(ch);
    cout << "Reversed string: "<< ch;
    return 0;
}
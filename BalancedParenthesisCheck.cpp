/* This program checks if the parenthesis are balanced in an input expression. */
#include <iostream>
#include <stack>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

bool isPairOf(string s){
    if(s == "{}" || s == "[]" || s == "()")
        return true;
    else
        return false;
}

bool isStringBalaced(char c[]){
    stringstream stream;
    string s;
    bool isBalanced = false;
    stack<char> st;
    int nSize = strlen(c);
    for(int i=0; i<nSize; i++){
        if(c[i] == '{' || c[i] == '(' || c[i] == '['){
            st.push(c[i]);
        } else if(c[i] == '}' || c[i] == ')' || c[i] == ']') {
            if(st.empty()) st.push(c[i]);
            stream << st.top() << c[i];
            stream >> s;
            if(st.empty() || !isPairOf(s))
                isBalanced = false;
            else
                st.pop();
        }
    }
    if(st.empty()) isBalanced = true;
    return isBalanced;
}


int main() {
    char c[50];
    cout << "Enter String with paranthesis: \n";
    cin >> c;
    if(isStringBalaced(c)) 
        cout << "String is balanced!\n";
    else 
        cout << "Not Balanced!";
    return 0;
}
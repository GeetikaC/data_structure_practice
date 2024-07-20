/* This program converts a given Infix expression into Postfix or Prefix. */

#include <iostream>
#include <stack>
#include <ctype.h>
#include <algorithm>

using namespace std;

int assignPrecedence(char val){
    string str1 = "{}()[]";
    string str2 = "/*";
    string str3 = "+-";
    int res = 0;
    int found = str1.find(val);
    if (found != string::npos) {
        res = 3;
        return res;
    }
    found = str2.find(val);
    if (found != string::npos) {
        res = 2;
        return res;
    }
    found = str3.find(val);
    if (found != string::npos) {
        res = 1;
        return res;
    }
    return res;
}

bool isOpeningBraces(char val){
    string strBracket = "{([";
    int found = strBracket.find(val);
    if(found != string::npos){
        return true;
    }
    return false;
}

bool isClosingBraces(char val){
    string strBracket = "})]";
    int found = strBracket.find(val);
    if(found != string::npos){
        return true;
    }
    return false;
}

bool isHigherPrecedence(char val1, char val2){
    bool flag = false;
    if(!isOpeningBraces(val1) && assignPrecedence(val1)>=assignPrecedence(val2)){
        flag = true;
    }
    return flag;
}

string covertInfixToPostfix(string str) {
    string result;
    stack<char> stk;
    for(auto ch: str){
        if(isalnum(ch))
        {
            result += ch;
        } else if(isOpeningBraces(ch)){
            stk.push(ch);
        } else if(isClosingBraces(ch)){
            while(!stk.empty() && !isOpeningBraces(stk.top())){
                result += stk.top();
                stk.pop();
            }
            stk.pop();
        } else{
            while(!stk.empty() && isHigherPrecedence(stk.top(),ch)){
                result += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    return result;
}

string covertInfixToPrefix(string str) {
    string result;
    stack<char> stk;
    int size = str.size();
    reverse(str.begin(), str.end());//Reverse infix
    for(int i = 0; i < size; i++){//Replace ( with ) and ) with (
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
    result = covertInfixToPostfix(str);
    reverse(result.begin(), result.end());//Reverse postfix
    return result;
}

int main(){
    int choice;
    string str;
    cout << "Enter which type of expression (1)Prefix (2)Postfix: \n";
    cin >> choice;
    cout << "Enter the expression: \n";
    cin >> str;
    switch(choice){
        case 1: cout << covertInfixToPrefix(str);
                break;
        case 2: cout << covertInfixToPostfix(str);
                break;
        default: cout << "Try again.";
                break;
    }
    return 0;
}
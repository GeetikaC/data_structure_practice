/*  This program solves a given prefix or postfix expression using a stack. 
    This is only for single digit numerals and no space in the input expression 
    is allowed */

#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

int evaluate(int val1, int val2, char chOperator){
    int res;
    switch(chOperator){
        case '+': res = val1 + val2;
                  break;
        case '-': res = val1 - val2;
                  break;
        case '*': res = val1 * val2;
                  break;
        case '/': res = val1 / val2;
                  break;
        case '%': res = val1 % val2;
                  break;
        default: res = 0;
                  break;
    }
    return res;   
}

int prefixSolved(string str) {//need to scan from right to left for a prefix expression
    int result;
    stack<char> stk;
    for(int i=str.size()-1; i>=0; i--){
        if(isdigit(str.at(i))){
            int val = str.at(i) - '0';//to convert from char to int
            stk.push(val);
        } else {
            int val1 = stk.top();//first operand popped is the first val in expression
            stk.pop();
            int val2 = stk.top();//second operand popped is the second val in expression
            stk.pop();
            result = evaluate(val1,val2,str.at(i));
            stk.push(result);
        }
    }
    return stk.top();
}

int postfixSolved(string str) {//scanning naturally from left to right for a postfix expression
    int result;
    stack<char> stk;
    for(auto ch : str){
        if(isdigit(ch)){
            int val = ch - '0';//to convert from char to int
            stk.push(val);
        } else {
            int val2 = stk.top();//first operand popped is the second val in expression
            stk.pop();
            int val1 = stk.top();//second operand popped is the first val in expression
            stk.pop();
            result = evaluate(val1,val2,ch);
            stk.push(result);
        }
    }
    return stk.top();
}

int main(){
    int choice;
    string str;
    cout << "Enter which type of expression (1)Prefix (2)Postfix: \n";
    cin >> choice;
    cout << "Enter the expression: \n";
    cin >> str;
    switch(choice){
        case 1: cout << prefixSolved(str);
                break;
        case 2: cout << postfixSolved(str);
                break;
        default: cout << "Try again.";
                break;
    }
    return 0;
}
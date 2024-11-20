#include <iostream>
#include <stack>
using namespace std;
#define endl "\n"

// Check if the parentheses are balanced
bool solve(string p){
    stack<char> b; // Stack to store the opening parentheses
    
    for(char c: p){
        if(c=='{' || c=='(' || c=='[') 
            b.push(c); // Push the opening parentheses
        else{
            if(b.empty()) return false; // return false if there is no opening parentheses

            if(c == ')' && b.top()=='('){
                b.pop();
            }else if(c == '}' && b.top()=='{'){
                b.pop();
            }else if(c == ']' && b.top()=='['){
                b.pop();
            }
            else{
                return false;
            }
        }
    }
    if (b.size()) return false; //if the stack is not empty, then the string is not balanaced
    return true;
}
int main(){
    string s;
    cout << "Enter the string of parentheses: ";
    getline(cin, s);
    cout << (solve(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}

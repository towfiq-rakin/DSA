/* This code shows how to check a palindrome
string using stack.
However, i'm using Stack library to reduce the size */

#include <iostream>
#include <stack>
using namespace std;
// Check if the palindrome is valid
bool solve(string p){
    stack<char> s;
    // Push the elements of the string in the stack
    for(int i=0; i<p.size(); ++i){
        s.push(p[i]);
    }
    // Compare the elements of the string with the stack
    for(int i=0; i<p.size(); ++i){
        if(p[i] != s.top()) return false; // return false if the elements are not equal
        s.pop(); // Remove the top element of the stack
    }
    return true;
}
int main(){
    string s;
    cout << "Enter the a String: ";
    getline(cin, s);
    cout << (solve(s) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}

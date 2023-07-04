/*
Question 2
Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is valid*.

The following rules define a valid string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"

Output:
true
*/




#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    stack<int> leftParenStack;
    stack<int> asteriskStack;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            leftParenStack.push(i);
        } else if (c == '*') {
            asteriskStack.push(i);
        } else {
            if (!leftParenStack.empty()) {
                leftParenStack.pop();
            } else if (!asteriskStack.empty()) {
                asteriskStack.pop();
            } else {
                return false;
            }
        }
    }

    while (!leftParenStack.empty() && !asteriskStack.empty()) {
        int leftIndex = leftParenStack.top();
        int asteriskIndex = asteriskStack.top();
        if (leftIndex > asteriskIndex) {
            return false;
        }
        leftParenStack.pop();
        asteriskStack.pop();
    }

    return leftParenStack.empty();
}

int main() {
    string s = "()";
    bool result = checkValidString(s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
/*
Question 7

Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"

Output: true

Explanation:
Both s and t become "ac".
*/



#include <bits/stdc++.h>
using namespace std;


bool backspaceCompare(string s, string t) {
    stack<char> stackS, stackT;

    // Process string s
    for (char c : s) {
        if (c != '#') {
            stackS.push(c);
        } else if (!stackS.empty()) {
            stackS.pop();
        }
    }

    // Process string t
    for (char c : t) {
        if (c != '#') {
            stackT.push(c);
        } else if (!stackT.empty()) {
            stackT.pop();
        }
    }

    // Compare the contents of the stacks
    return stackS == stackT;
}

int main() {
    string s = "ab#c";
    string t = "ad#c";

    bool result = backspaceCompare(s, t);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
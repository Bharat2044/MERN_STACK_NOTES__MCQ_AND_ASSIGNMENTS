/*
Question 7

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"

Output: "aaabcbc"
*/




#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString;
    int currentCount = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentCount = currentCount * 10 + (c - '0');
        } else if (c == '[') {
            countStack.push(currentCount);
            stringStack.push(currentString);
            currentCount = 0;
            currentString.clear();
        } else if (c == ']') {
            string decodedString = stringStack.top();
            stringStack.pop();
            int repeatCount = countStack.top();
            countStack.pop();

            for (int i = 0; i < repeatCount; i++) {
                decodedString += currentString;
            }

            currentString = decodedString;
        } else {
            currentString += c;
        }
    }

    return currentString;
}

int main() {
    string s = "3[a]2[bc]";
    string decodedString = decodeString(s);

    cout << decodedString << endl;

    return 0;
}
/*
Question 6

Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of shifts on* s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"

Output:
true
*/



#include <bits/stdc++.h>
using namespace std;

bool canShiftString(const string& s, const string& goal) {
    // Concatenate the original string with itself
    string concatenated = s + s;

    // Check if the target string is a substring of the concatenated string
    if (concatenated.find(goal) != string::npos) {
        return true;
    }

    return false;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    bool result = canShiftString(s, goal);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
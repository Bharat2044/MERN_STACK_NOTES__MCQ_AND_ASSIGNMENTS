/*
Question 8

Given two strings s and goal, return true *if you can swap two letters in* s *so the result is equal to* goal*, otherwise, return* false*.*

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: s = "ab", goal = "ba"
Output: true

Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
*/




#include <bits/stdc++.h>
using namespace std;

bool buddyStrings(string s, string goal) {
    int n = s.length();
    int m = goal.length();

    // Check if the lengths of s and goal are equal
    if (n != m) {
        return false;
    }

    // Check if s and goal are equal
    if (s == goal) {
        // Check if there are any repeated characters in s
        int charCount[26] = {0};
        for (char c : s) {
            charCount[c - 'a']++;
            if (charCount[c - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }

    // Find the indices where s and goal differ
    int firstDiff = -1;
    int secondDiff = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            if (firstDiff == -1) {
                firstDiff = i;
            } else if (secondDiff == -1) {
                secondDiff = i;
            } else {
                return false; // More than 2 differences
            }
        }
    }

    // Check if swapping the characters at the differing indices produces goal
    if (secondDiff != -1 && s[firstDiff] == goal[secondDiff] && s[secondDiff] == goal[firstDiff]) {
        return true;
    }

    return false;
}

int main() {
    string s = "ab";
    string goal = "ba";

    bool result = buddyStrings(s, goal);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
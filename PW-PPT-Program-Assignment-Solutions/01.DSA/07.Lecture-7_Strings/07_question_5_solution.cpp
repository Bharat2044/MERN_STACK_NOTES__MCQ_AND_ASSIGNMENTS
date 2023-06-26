/*
Question 5

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

Example 1:
Input: s = "abcdefg", k = 2

Output:
"bacdfeg"
*/



#include <bits/stdc++.h>
using namespace std;

void reverseString(string& s, int k) {
    int n = s.length();
    for (int i = 0; i < n; i += 2 * k) {
        int start = i;
        int end = min(i + k - 1, n - 1);
        
        // Reverse the first k characters
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
}

int main() {
    string s = "abcdefg";
    int k = 2;

    reverseString(s, k);
    cout << s << endl;
    
    return 0;
}
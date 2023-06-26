/*
Question 2

Given a string num which represents an integer, return true *if* num *is a strobogrammatic number*.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Example 1:

Input: num = "69"

Output:

true
*/




#include <bits/stdc++.h>
using namespace std;

bool isStrobogrammatic(const string& num) {
    unordered_map<char, char> strobogrammaticMap{
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };

    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        if (strobogrammaticMap.find(num[left]) == strobogrammaticMap.end() ||
            strobogrammaticMap[num[left]] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string num = "69";

    bool isStrobogrammaticNum = isStrobogrammatic(num);

    cout << (isStrobogrammaticNum ? "true" : "false") << endl;

    return 0;
}
/*
Question 3

Given an integer array nums sorted in non-decreasing order, return *an array of the squares of each number sorted in non-decreasing order*.

Example 1:

Input: nums = [-4,-1,0,3,10]

Output: [0,1,9,16,100]

Explanation: After squaring, the array becomes [16,1,0,9,100].

After sorting, it becomes [0,1,9,16,100].
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> squares;
    for (int num : nums) {
        squares.push_back(num * num);
    }
    sort(squares.begin(), squares.end());
    return squares;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Question 6
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

Example 1:

Input: nums = [-4,-1,0,3,10]

Output: [0,1,9,16,100]

Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100]
*/





#include <bits/stdc++.h>
using namespace std;


vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());

    int left = 0;
    int right = nums.size() - 1;
    int index = nums.size() - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
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
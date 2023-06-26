/*
Question 7
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
*/



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<vector<int>> ranges;
    long long next = lower; 
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > next) {
            // Found a missing range
            ranges.push_back({(int)next, nums[i] - 1});
        }
        
        next = (long long)nums[i] + 1;
    }
    
    if (next <= upper) {
        // Check for missing range after the last element of nums
        ranges.push_back({(int)next, upper});
    }
    
    return ranges;
}

int main() {
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    
    vector<vector<int>> result = findMissingRanges(nums, lower, upper);
    
    for (const auto& range : result) 
        cout << "[" << range[0] << "," << range[1] << "] ";
    
    return 0;
}
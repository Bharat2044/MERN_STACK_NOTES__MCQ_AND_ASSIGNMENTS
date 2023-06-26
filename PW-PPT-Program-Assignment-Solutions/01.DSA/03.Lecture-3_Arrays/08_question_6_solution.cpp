/*
Question 6
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/



#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    
    for (const auto& num : nums) {
        // XOR operation cancels out the pairs of duplicate elements
        result ^= num;
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 2, 1};
    
    int result = singleNumber(nums);
    cout << result << endl;
    
    return 0;
}
/*
Question 7
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true
*/




#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isMonotonic(const vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) 
            decreasing = false;
        if (nums[i] < nums[i - 1]) 
            increasing = false;
    }

    return increasing || decreasing;
}

int main() {
    vector<int> nums = {1, 2, 2, 3};

    bool result = isMonotonic(nums);

    cout << boolalpha << result << endl;

    return 0;
}
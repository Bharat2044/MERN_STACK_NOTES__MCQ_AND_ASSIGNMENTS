/*
Question 4

Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

Example 1:

Input: nums = [0,1]

Output: 2

Explanation:

[0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/




#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int maxLength = 0;
    int count = 0;
    unordered_map<int, int> countMap;
    countMap[0] = -1;

    for (int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1 ? 1 : -1);

        if (countMap.find(count) != countMap.end()) {
            maxLength = max(maxLength, i - countMap[count]);
        } else {
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0, 1};

    int maxLength = findMaxLength(nums);

    cout << maxLength << endl;

    return 0;
}
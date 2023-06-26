/*
Question 6

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return *an array of all the integers that appears twice*.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]

Output:

[2,3]
*/




#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    for (int num : nums) {
        int index = abs(num) - 1;
        if (nums[index] < 0) {
            duplicates.push_back(abs(num));
        } else {
            nums[index] = -nums[index];
        }
    }
    return duplicates;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDuplicates(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Question 3
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
    int maxLength = 0;

    // Count the frequencies of each number
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Find the maximum length of harmonious subsequence
    for (auto it : frequencyMap) {
        int num = it.first;
        int frequency = it.second;

        if (frequencyMap.count(num + 1)) {
            int harmoniousFrequency = frequencyMap[num + 1];
            maxLength = max(maxLength, frequency + harmoniousFrequency);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    int result = findLHS(nums);

    cout << result << endl;

    return 0;
}

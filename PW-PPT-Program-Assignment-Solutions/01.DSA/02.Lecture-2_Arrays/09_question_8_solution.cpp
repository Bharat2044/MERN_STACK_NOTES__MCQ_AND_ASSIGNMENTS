/*
Question 8
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minScore(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int minimum = nums[0];
    int maximum = nums[n - 1];

    int result = maximum - minimum;

    for (int i = 1; i < n - 1; i++) {
        int newMin = min(minimum + k, nums[i] - k);
        int newMax = max(maximum - k, nums[i] + k);
        result = min(result, newMax - newMin);
    }

    return result;
}

int main() {
    vector<int> nums = {1};
    int k = 0;

    int result = minScore(nums, k);

    cout << result << endl;

    return 0;
}
/*
Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maximumProduct(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

    int product2 = nums[0] * nums[1] * nums[n - 1];

    // Return the maximum product
    return max(product1, product2);
}

int main() {
    vector<int> nums = {1, 2, 3};

    int result = maximumProduct(nums);

    cout << result << endl;

    return 0;
}

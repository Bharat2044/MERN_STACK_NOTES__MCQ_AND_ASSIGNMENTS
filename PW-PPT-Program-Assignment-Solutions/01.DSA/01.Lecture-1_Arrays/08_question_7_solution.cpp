/*
Q7. Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/



#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    
    while (right < n) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    // Print the resulting array
    for (int num : nums) 
        cout << num << " ";
    
    cout << endl;

    return 0;
}
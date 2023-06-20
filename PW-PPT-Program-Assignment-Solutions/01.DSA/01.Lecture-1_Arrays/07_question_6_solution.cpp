/*
Q6. Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]

Output: true
*/



#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;

    for (int num : nums) {
        if (numSet.count(num)) {
            return true;
        }
        numSet.insert(num);
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    bool result = containsDuplicate(nums);

    cout << boolalpha << result << endl;

    return 0;
}
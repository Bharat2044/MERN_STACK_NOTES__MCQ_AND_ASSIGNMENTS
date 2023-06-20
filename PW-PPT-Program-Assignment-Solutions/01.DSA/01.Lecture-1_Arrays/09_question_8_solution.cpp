/*
Q8. You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
*/



#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result;
    unordered_set<int> numSet;
    int n = nums.size();
    int duplicate = -1;
    int missing = -1;

    // Find the duplicate number
    for (int num : nums) {
        if (numSet.count(num)) {
            duplicate = num;
        }
        numSet.insert(num);
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (!numSet.count(i)) {
            missing = i;
            break;
        }
    }

    result.push_back(duplicate);
    result.push_back(missing);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};

    vector<int> result = findErrorNums(nums);

    // Print the resulting array
    for (int num : result) 
        cout << num << " ";
    cout << endl;

    return 0;
}

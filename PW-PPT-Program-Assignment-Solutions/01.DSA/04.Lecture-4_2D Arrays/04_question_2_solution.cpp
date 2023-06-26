/*
Question 2

Given two 0-indexed integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

- answer[0] *is a list of all distinct integers in* nums1 *which are not present in* nums2*.*
- answer[1] *is a list of all distinct integers in* nums2 *which are not present in* nums1.

Note that the integers in the lists may be returned in any order.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]

Output: [[1,3],[4,6]]

Explanation:

For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
*/




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDistinctIntegers(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> distinctNums1;
    vector<int> distinctNums2;

    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            distinctNums1.push_back(num);
        }
    }

    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            distinctNums2.push_back(num);
        }
    }

    return {distinctNums1, distinctNums2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = findDistinctIntegers(nums1, nums2);

    for (int num : result[0]) 
        cout << num << " ";
    cout << endl;

    for (int num : result[1]) 
        cout << num << " ";

    return 0;
}
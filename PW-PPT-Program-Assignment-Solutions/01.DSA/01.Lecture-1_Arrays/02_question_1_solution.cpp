/*
Q1. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1]
*/


#include <iostream>
using namespace std;

void twoSum(int arr[], int n, int x) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == x) 
                cout << "[" << i << ", " << j << "], ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
        
    int target;
    cin >> target;
        
    twoSum(arr, n, target);

    return 0;
}

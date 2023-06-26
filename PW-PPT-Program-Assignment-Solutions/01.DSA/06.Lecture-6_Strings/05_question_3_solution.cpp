/*
uestion 3

Given an array of integers arr, return *true if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]

Output:

false
*/



#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    // Check if the array has at least 3 elements
    if (n < 3) {
        return false;
    }

    // Check the increasing part of the array
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }

    // Check if the peak is not at the beginning or the end
    if (i == 0 || i == n - 1) {
        return false;
    }

    // Check the decreasing part of the array
    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }

    // If we reached the end, it is a valid mountain array
    return i == n - 1;
}

int main() {
    vector<int> arr = {2, 1};

    bool isValidMountain = validMountainArray(arr);

    cout << (isValidMountain ? "true" : "false") << endl;

    return 0;
}

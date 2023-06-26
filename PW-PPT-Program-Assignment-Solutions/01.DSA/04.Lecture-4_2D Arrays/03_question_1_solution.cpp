/*
Question 1
Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

Output: [1,5]

Explanation: Only 1 and 5 appeared in the three arrays.
*/




#include <bits/stdc++.h>
using namespace std;

std::vector<int> findCommonElements(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    std::vector<int> result;
    int i = 0, j = 0, k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 2, 5, 7, 9};
    std::vector<int> arr3 = {1, 3, 4, 5, 8};

    std::vector<int> result = findCommonElements(arr1, arr2, arr3);

    for (int num : result) 
        std::cout << num << " ";

    return 0;
}

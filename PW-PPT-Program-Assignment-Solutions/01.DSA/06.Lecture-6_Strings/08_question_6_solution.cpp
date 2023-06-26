/*
Question 6

An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original *if* changed *is a doubled array. If* changed *is not a doubled array, return an empty array. The elements in* original *may be returned in any order*.

Example 1:

Input: changed = [1,3,4,2,6,8]

Output: [1,3,4]

Explanation: One possible original array could be [1,3,4]:

- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.

Other original arrays could be [4,3,1] or [3,1,4].
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> original;

    if (changed.size() % 2 != 0) {
        return original;  // If the size of changed is odd, it cannot be a doubled array
    }

    unordered_map<int, int> count;  // Map to store the frequency of each element

    // Count the frequency of elements in changed
    for (int num : changed) {
        count[num]++;
    }

    for (int num : changed) {
        if (count[num] == 0) {
            continue;  // Element has already been used
        }

        if (count[2 * num] == 0) {
            return {};  // 2 * num is not present in changed
        }

        original.push_back(num);
        count[num]--;
        count[2 * num]--;
    }

    return original;
}

int main() {
    vector<int> changed = {1, 3, 4, 2, 6, 8};

    vector<int> original = findOriginalArray(changed);

    if (original.empty()) {
        cout << "No valid original array found." << endl;
    } 
    else {
        for (int num : original) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
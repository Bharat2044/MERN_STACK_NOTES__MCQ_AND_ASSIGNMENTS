/*
Question 5
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]

Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    // Start from the least significant digit
    for (int i = n - 1; i >= 0; i--) {
        // Increment the current digit by one
        digits[i]++;
        
        // If the digit becomes 10, set it to 0 and carry the one to the next digit
        if (digits[i] == 10) {
            digits[i] = 0;
        } else {
            // No carry required, so we can return the result
            return digits;
        }
    }
    
    // If we reach here, it means all digits were 9s and we need to add an additional digit
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits = {1, 2, 3};
    
    vector<int> result = plusOne(digits);
    
    for (const auto& digit : result) 
        cout << digit << " ";
    
    return 0;
}
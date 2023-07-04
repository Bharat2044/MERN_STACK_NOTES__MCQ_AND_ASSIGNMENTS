/*
Question 1

Given two strings s1 and s2, return *the lowest ASCII sum of deleted characters to make two strings equal*.

Example 1:

Input: s1 = "sea", s2 = "eat"

Output: 231

Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.

Deleting "t" from "eat" adds 116 to the sum.

At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/


#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a 2D vector to store the minimum ASCII sum for each subproblem
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the first row and column of the dp table
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    // Fill the rest of the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match, no deletion needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters don't match, consider deletion
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    // Return the minimum ASCII sum to make the strings equal
    return dp[m][n];
}

int main() {
    string s1 = "sea";
    string s2 = "eat";
    
    int result = minimumDeleteSum(s1, s2);
    cout << result << endl;
    return 0;
}
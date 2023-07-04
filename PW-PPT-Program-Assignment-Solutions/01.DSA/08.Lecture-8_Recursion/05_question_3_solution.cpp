/*
Question 3
Given two strings word1 and word2, return *the minimum number of steps required to make* word1 *and* word2 *the same*.

In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"

Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/



#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    // Create a 2D vector to store the minimum steps for each subproblem
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the first row and column of the dp table
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the rest of the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                // Characters match, no deletion needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters don't match, consider deletion
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the minimum number of steps to make the strings the same
    return dp[m][n];
}

int main() {
    string word1 = "sea";
    string word2 = "eat";
    
    int result = minDistance(word1, word2);
    cout << result << endl;
    return 0;
}
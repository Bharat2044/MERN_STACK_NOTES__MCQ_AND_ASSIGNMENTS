/*
Question 1

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

Example 1:

Input: s = "IDID"

Output:

[0,4,1,3,2]
*/




#include <bits/stdc++.h>
using namespace std;

vector<int> findPermutation(string s) {
    int n = s.size() + 1;
    vector<int> perm(n);

    // Initialize the permutation as [0, 1, 2, ..., n]
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || s[i - 1] == 'I') {
            reverse(perm.begin() + j, perm.begin() + i);
            j = i;
        }
    }

    return perm;
}

int main() {
    string s = "IDID";
    vector<int> perm = findPermutation(s);

    for (int num : perm) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
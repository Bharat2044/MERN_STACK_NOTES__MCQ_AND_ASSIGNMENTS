/*
Question 6

Given two strings s and p, return *an array of all the start indices of* p*'s anagrams in* s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length()) {
        return result;
    }

    array<int, 26> sCount = {0};
    array<int, 26> pCount = {0};

    // Count the occurrences of characters in p
    for (char c : p) {
        pCount[c - 'a']++;
    }

    int windowSize = p.length();

    // Count the occurrences of characters in the first window of s
    for (int i = 0; i < windowSize; i++) {
        sCount[s[i] - 'a']++;
    }

    // Compare the counts of characters in the sliding window with pCount
    for (int i = windowSize; i <= s.length(); i++) {
        if (sCount == pCount) {
            result.push_back(i - windowSize);
        }

        // Slide the window by moving the left and right pointers
        if (i < s.length()) {
            sCount[s[i] - 'a']++;              // Include the next character
            sCount[s[i - windowSize] - 'a']--; // Remove the leftmost character
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> indices = findAnagrams(s, p);

    for (int index : indices) 
        cout << index << " ";

    return 0;
}
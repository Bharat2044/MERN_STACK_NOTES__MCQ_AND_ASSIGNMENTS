/*
Question 4

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"

Output: "s'teL ekat edoCteeL tsetnoc"
*/



#include <bits/stdc++.h>
using namespace std;

string reverseWords(const string& s) {
    istringstream iss(s);
    vector<string> words;

    // Split the sentence into words
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse each word
    for (string& w : words) {
        reverse(w.begin(), w.end());
    }

    // Reconstruct the sentence with reversed words
    ostringstream oss;
    for (const string& w : words) {
        oss << w << ' ';
    }

    string result = oss.str();
    // Remove trailing whitespace
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    string s = "Let's take LeetCode contest";
    string reversed = reverseWords(s);

    cout << reversed << endl;

    return 0;
}
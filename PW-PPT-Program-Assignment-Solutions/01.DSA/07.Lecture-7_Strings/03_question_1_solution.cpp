/*
Question 1

Given two strings s and t, *determine if they are isomorphic*.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"

Output: true
*/




#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < s.length(); i++) {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT.find(sChar) == sToT.end() && tToS.find(tChar) == tToS.end()) {
            // Both mappings are not present, create new mappings
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        } else if (sToT[sChar] != tChar || tToS[tChar] != sChar) {
            // Either of the mappings is different, strings are not isomorphic
            return false;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    bool isomorphic = isIsomorphic(s, t);

    cout << (isomorphic ? "true" : "false") << endl;

    return 0;
}



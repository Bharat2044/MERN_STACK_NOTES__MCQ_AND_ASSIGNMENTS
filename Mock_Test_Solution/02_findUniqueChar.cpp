#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    // Count the occurrences of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Find the first non-repeating character
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1; 
}

int main() {
    string s;
    cin >> s;
    
    int index = firstUniqChar(s);

    cout << index << endl;

    return 0;
}

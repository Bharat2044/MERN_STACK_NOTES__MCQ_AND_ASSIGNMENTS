/*
Question 8
Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/




#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    // Check for any overlap between consecutive intervals
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; // Overlapping intervals, cannot attend all meetings
        }
    }

    return true; // No overlapping intervals, can attend all meetings
}

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    bool result = canAttendMeetings(intervals);

    cout << boolalpha << result << endl;

    return 0;
}

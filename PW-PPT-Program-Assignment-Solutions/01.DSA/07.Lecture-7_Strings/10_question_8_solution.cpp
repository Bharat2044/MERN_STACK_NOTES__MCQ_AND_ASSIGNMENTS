/*
Question 8

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]

Output: true
*/


#include <bits/stdc++.h>
using namespace std;


bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n <= 2) {
        return true; // If there are 2 or fewer points, they always form a straight line
    }

    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    
    // Calculate the slope between the first two points
    int dx = x1 - x0;
    int dy = y1 - y0;

    // Check the slope between the first two points against the slopes of other points
    for (int i = 2; i < n; i++) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];
        
        // Calculate the slope between the current point and the first point
        int currDx = x - x0;
        int currDy = y - y0;

        // If the slopes are not equal, return false
        if (dy * currDx != dx * currDy) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};

    bool result = checkStraightLine(coordinates);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
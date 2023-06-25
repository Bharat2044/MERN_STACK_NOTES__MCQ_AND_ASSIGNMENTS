#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int nonZeroIndex = 0;

    // Move all non-zero elements to the beginning of the array
    for (int i=0; i<n; i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }

    // Fill the remaining positions with zeros
    while (nonZeroIndex < n) {
        nums[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums;
    
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        
        nums.push_back(x);
    }

    moveZeroes(nums);

    for (int i=0; i<nums.size(); i++) 
        cout << nums[i] << " ";
    
    cout << endl;

    return 0;
}

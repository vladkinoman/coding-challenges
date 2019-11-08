#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private: bool jumpToNextIndex(vector<int>& nums, int index) {
        int n = nums.size() - 1;
        
        if (index >= n)
            return true;
        
        int furthestJump = std::min(index + nums[index], n);
        for (int nextIndex = furthestJump; nextIndex > index; --nextIndex) {
            if (jumpToNextIndex(nums, nextIndex))
                return true;
        }
        
        return false;
    }
    
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++)
            if (nums[i] < 0)
                throw std::invalid_argument("Array should contain non-negative integers.");
        
        return jumpToNextIndex(nums, 0);
    }
};

int main()
{
    vector<int> nums;
    // example 1 - true
    /*nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);*/
    // example 2 - false
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
	
    Solution newSolution;
    cout << newSolution.canJump(nums) << endl;
    return 0;
}

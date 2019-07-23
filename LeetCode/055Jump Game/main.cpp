#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool is_reachable = false;
        int i = 0;
        for(; i < nums.size() - 1; i += nums[i])
	    if(nums[i] == 0) break;
        if(i == nums.size() - 1)
            is_reachable = true;
	return is_reachable;
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

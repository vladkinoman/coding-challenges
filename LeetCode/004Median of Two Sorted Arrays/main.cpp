#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    double findMedianSortedArray(vector<int> & nums)
	{
		int n = nums.size();
		return (n % 2 == 0) ? (double)(nums[(double)n / 2 - 1] 
		+ nums[(double)(n + 2) / 2 - 1]) / 2
		: nums[round((double)n / 2) - 1];
	}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
		vector<int> merged_nums(n);
        if(nums1.size() > 0 && nums2.size() > 0)
        {
            merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged_nums.begin());
            return findMedianSortedArray(merged_nums);
        }
        else if(nums1.size() > 0 && nums2.size() <= 0)
            return findMedianSortedArray(nums1);
        else if(nums1.size() <= 0 && nums2.size() > 0)
            return findMedianSortedArray(nums2);
        else
            return 0;
    }
};

int main()
{
	// test case # 1
	vector<int> nums1;
	vector<int> nums2;
		
	nums2.push_back(1);

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	Solution newSolution1;
	cout << newSolution1.findMedianSortedArrays(nums1, nums2) << endl;

	// test case # 2
	vector<int> nums21;
	vector<int> nums22;
	
	nums21.push_back(1);	
	nums21.push_back(3);

	nums22.push_back(2);

	sort(nums21.begin(), nums21.end());
	Solution newSolution2;
	cout << newSolution2.findMedianSortedArrays(nums21, nums22) << endl;
}

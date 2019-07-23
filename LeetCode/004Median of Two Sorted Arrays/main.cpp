#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med1 = 0.0;
	double med2 = 0.0;
        for(int i = 0; i < nums1.capacity(); i++)
        	med1 += nums1.at(i);
        med1 /= 2.0;
        for(int i = 0; i < nums2.capacity(); i++)
        	med2 += nums2.at(i);
        med2 /= 2.0;
        return (med1 + med2) / 2.0;
    }
};

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	int x = 0;
	
	nums1.push_back(2);	
	nums1.push_back(1);
	
	nums2.push_back(4);	
	nums2.push_back(3);

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	Solution newSolution;
	cout << newSolution.findMedianSortedArrays(nums1, nums2) << endl;
}

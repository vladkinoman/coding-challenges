#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int med1 = med2 = 0;
        for(int i = 0; i < nums1.capacity(); i++)
        	med1 += nums1.at(i);
        med1 /= 2;
        for(int i = 0; i < nums2.capacity(); i++)
        	med2 += nums2.at(i);
        med2 /= 2;
        return (med1 + med2) / 2;
    }
};

int main()
{
	vector<int> nums1;
	vector<int> nums2;
	int x = 0;
	
	while(cin >> x)
		nums1.push_back(x);
	x = 0;
	while(cin >> x)
		nums2.push_back(x);
	
	sort(nums1.begin(), nums2.end());

	Solution newSolution;
	cout << newSolution.findMedianSortedArrays(nums1, nums2) << endl;
}
class Solution {
    public int rob(int[] nums) {
        for (int i = 0; i < nums.length; ++i)
    		if(nums[i] < 0)
    			throw new IllegalArgumentException("Amount of money must be non-negative.");
    
	    int sumFromFirstHouse = 0;
	    for (int i = 0; i < nums.length; i+=2)
	    	sumFromFirstHouse += nums[i];
	    int sumFromSecondHouse = 0;
	    for (int i = 1; i < nums.length; i+=2)
	    	sumFromSecondHouse += nums[i];
	    if(sumFromFirstHouse > sumFromSecondHouse)
	    	return sumFromFirstHouse;
	    else
	    	return sumFromSecondHouse;
}
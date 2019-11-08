class SlowRecurrentSolution {
    private boolean jumpToNextIndex(int[] nums, int index) {
        int n = nums.length - 1;
        
        if (index >= n)
            return true;
        
        int furthestJump = Math.min(index + nums[index], n);
        for (int nextIndex = furthestJump; nextIndex > index; nextIndex--) {    
            if (jumpToNextIndex(nums, nextIndex))
                return true;
        }
        
        return false;
    }
    
    public boolean canJump(int[] nums) {
        int n = nums.length - 1;
        for (int i = 0; i <= n; i++)
            if (nums[i] < 0) 
                throw new IllegalArgumentException();
        
        return jumpToNextIndex(nums, 0);
    }
}
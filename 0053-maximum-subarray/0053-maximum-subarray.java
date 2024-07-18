class Solution {
    public int maxSubArray(int[] nums) {
         int maxsofar = Integer.MIN_VALUE;
        int max_ending_here = 0;

        for(int i=0;i<nums.length;i++){

            max_ending_here = max_ending_here+nums[i];
            if(maxsofar<max_ending_here){
                maxsofar=max_ending_here;
            }
            if(max_ending_here<0){
                max_ending_here=0;
            }
            
        }
        return maxsofar;
    }
}
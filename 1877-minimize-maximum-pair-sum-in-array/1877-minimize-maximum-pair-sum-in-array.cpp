class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0, j=n-1;
        int minSum=INT_MIN;
        while(i<=j){

            minSum = max(minSum,nums[i]+nums[j]);
            i++;
            j--;
        }

        return minSum;
    }
};
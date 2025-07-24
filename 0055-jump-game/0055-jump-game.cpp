class Solution {
public:
    int dp[10001];
    bool solve(vector<int>& nums,int i,int n){
        if(i>=n-1 )return true;
        if(dp[i]!=-1)return dp[i];
        
        for(int j=1;j<=nums[i];j++){
            if(solve(nums,i+j,n)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n);
    }
};
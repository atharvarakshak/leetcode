class Solution {
public:
int dp[1000][1000][2];
    int solve(vector<int>& nums, int idx, int prev, int stat){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][prev][stat]!=-1){
            return dp[idx][prev][stat];
        }
        int take=0;
        if(stat==0 && nums[idx]>nums[prev] || stat==1 && nums[idx]<nums[prev] ){
            take = 1 + solve(nums,idx+1,idx, 1-stat);
        }
        int skip = solve(nums,idx+1,idx,stat);

        return dp[idx][prev][stat] = max(take,skip);
        
    }

    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return 1+max(solve(nums,1,0,0),solve(nums,1,0,1));
    }
};
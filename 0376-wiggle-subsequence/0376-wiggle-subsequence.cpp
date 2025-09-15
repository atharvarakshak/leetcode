class Solution {
public:

int solve(vector<int>& nums, int prev, int curr, bool isUp, vector<vector<vector<int>>>& dp) {
    if(curr == nums.size()) return 0;

    if(dp[prev+1][curr][isUp] != -1) return dp[prev+1][curr][isUp];

    int take = 0;
    // if no previous element or we can wiggle
    if(prev == -1 || (isUp && nums[curr] > nums[prev]) || (!isUp && nums[curr] < nums[prev])) {
        take = 1 + solve(nums, curr, curr+1, !isUp, dp);
    }

    int skip = solve(nums, prev, curr+1, isUp, dp);

    return dp[prev+1][curr][isUp] = max(take, skip);
}

    int wiggleMaxLength(vector<int>& nums) {
         int n = nums.size();
    // dp[prev+1][curr][isUp] = result
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n, vector<int>(2, -1)));

    return 1 + max(
        solve(nums, 0, 1, true, dp),   // start expecting up
        solve(nums, 0, 1, false, dp)   // start expecting down
    );
    }
};



class Solution {
public:
    int solve(vector<int>& jobDifficulty, int d, int idx, vector<vector<int>> &dp){
        if(d==1){
            int maxD = jobDifficulty[idx];
            for(int i=idx;i<jobDifficulty.size();i++){
                maxD = max(maxD,jobDifficulty[i]);
            }
            return maxD;
        }
        
        if(dp[d][idx]!=-1){
            return dp[d][idx];
        }
        int maxJob =jobDifficulty[idx], mini = INT_MAX;
        for(int i = idx; i<=jobDifficulty.size()-d; i++){
             maxJob = max(maxJob,jobDifficulty[i]);

             int res = maxJob + solve(jobDifficulty,d-1,i+1,dp);

            mini = min(mini,res);

        }   
        return dp[d][idx] = mini;

    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
   
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        if(n<d)return -1;
      
        return solve(jobDifficulty,d,0,dp);
        
    }
};
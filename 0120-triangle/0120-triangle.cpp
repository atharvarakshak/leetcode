class Solution {
public:
int dp[1000][1000];
    int solve(vector<vector<int>>& triangle, int n, int i, int j){
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        return  dp[i][j] = triangle[i][j] + min(solve(triangle, n , i+1,j), solve(triangle, n, i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp,-1,sizeof(dp));
        // return solve(triangle,n,0,0);
        vector<vector<int>> dp(n,vector<int>(n,-1));

           for(int i=0;i<n;i++) dp[n-1][i] = triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];


    }
};
class Solution {
public:
// LCS
    int minimumDeleteSum(string s1, string s2) {
        int totSum=0, n=s1.size(), m = s2.size();

        for(int i=0;i<n;i++)totSum+=s1[i];
        for(int i=0;i<m;i++)totSum+=s2[i];


        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        return totSum - 2*dp[n][m];

        
    }
};
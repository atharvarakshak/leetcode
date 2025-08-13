class Solution {
public:
    int dp[501][501];
    int lcs(string word1, string word2, int i, int j){

        if(i>=word1.size() || j>=word2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = 1+lcs(word1,word2,i+1,j+1);
        }

        return dp[i][j] = max(lcs(word1,word2,i+1,j),lcs(word1,word2,i,j+1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int l=lcs(word1,word2,0,0);
        return (word1.length()-l)+(word2.length()-l);
    }
};


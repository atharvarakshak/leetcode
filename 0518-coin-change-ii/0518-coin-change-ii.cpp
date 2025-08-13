class Solution {
public:
int dp[5001][301];
    int solve(vector<int>& coins, int amount, int i){
        if(i>=coins.size() || amount<0)return 0;

        if(amount==0)return 1;
        if(dp[amount][i]!=-1)return dp[amount][i];
        int take = solve(coins, amount-coins[i], i);
        int skip = solve(coins, amount, i+1);

        return dp[amount][i] = take+skip;


    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,0);

    }
};
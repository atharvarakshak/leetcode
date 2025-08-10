class Solution {
public:
int dp[1001][2][201];
    int solve(vector<int>& prices, int n ,int k,int buy, int i,int t){
        if(i==n || t>2*k){
            return 0;
        }
        if(dp[i][buy][t]!=-1)return dp[i][buy][t];
        int profit=0;
        if(buy){
            profit = max(-prices[i]+solve(prices, n, k,0,i+1,t+1),solve(prices, n, k,1,i+1,t));

        }
        else{
            profit = max(prices[i]+solve(prices, n,k, 1,i+1,t+1),solve(prices, n,k, 0,i+1,t));
        }

        return dp[i][buy][t] = profit;




    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
           memset(dp,-1,sizeof(dp));
        return solve(prices,n,k,1,0,0);
    }
};
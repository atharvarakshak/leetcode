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
        // return solve(prices,n,k,1,0,0);

         vector<vector<int>> buy(k + 1, vector<int>(n));
        //buy[t][i] = max profit after buying t'th stock on i'th index
        vector<vector<int>> profit(k + 1, vector<int>(n));
        //profit[t][i] = max profit after completing t tranx on i'th index

        for(int i = 0; i < n; i++)
        {
            for(int t = 1; t <= k; t++)
            {
                // max profit we can get on buying t'th stock here on i'th index
                // = (-item price) + profit after completing t-1 tranx on i-1'th index
                // or we have already bought t'th stock
                if(i) buy[t][i] = max(buy[t][i - 1], profit[t - 1][i - 1] - prices[i]);
                else buy[t][0] = -prices[i];

                // max profit after completing total of t tranx
                // = we completed t tranx on i-1'th index or we complete t tranx here
                if(i) profit[t][i] = max(profit[t][i - 1], prices[i] + buy[t][i]);
            }
        }
        
        return profit[k][n - 1];
    }
};
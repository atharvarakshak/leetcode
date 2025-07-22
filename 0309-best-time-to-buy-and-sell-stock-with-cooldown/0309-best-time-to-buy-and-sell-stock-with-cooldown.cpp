class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices, int n, int i,bool buy){
        if(i>=n)return 0;

        int maxP = 0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        if(buy){
            
            int buy = solve(prices,n,i+1,false)-prices[i];
            int not_buy = solve(prices,n,i+1,true);
            maxP = max({maxP,buy,not_buy});
        }
        else{
            int sale = prices[i]+solve(prices,n,i+2,true);
            int not_sale = solve(prices,n,i+1,false);
            maxP = max({maxP,sale,not_sale});
        }


        return dp[i][buy] = maxP;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));

        return solve(prices,n,0,true);      
    }
};
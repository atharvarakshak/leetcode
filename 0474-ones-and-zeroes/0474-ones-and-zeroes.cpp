class Solution {
public:
    vector<pair<int,int>> str;
    int dp[601][101][101];
    int solve(int m, int n, int i, int c1, int c2){
        if(i>=str.size() )return 0;

        if( c1>m || c2>n)return INT_MIN;
        if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];

        int take = 0;
        if(c1+str[i].first<=m &&  c2+str[i].second<=n){

         take = 1 + solve(m,n,i+1, c1+str[i].first, c2+str[i].second);
        }
        int skip = solve(m,n,i+1,c1,c2);

        return dp[i][c1][c2] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nu = strs.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nu;i++){
            int one=0,zero=0;

            for(int j=0; j<strs[i].size();j++){
               if(strs[i][j]=='0')zero++;
               else one++; 
            }
            str.push_back({zero,one});
        }

        return solve(m,n,0,0,0);


    }
};
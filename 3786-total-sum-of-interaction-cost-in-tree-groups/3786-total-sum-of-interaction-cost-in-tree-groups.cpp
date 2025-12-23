class Solution {
public:
    long long ans=0;
    vector<int> solve(int u, int p, vector<vector<int>>& G, vector<int> tot, vector<int> &group ){  

        vector<int> curr(21);

        curr[group[u]]=1;

        for(int x : G[u]){
            if(x==p) continue;
            auto c = solve(x, u, G, tot, group);

            for(int i=1; i<=20; i++){
                if(tot[i]){
                    ans += 1L * c[i] * (tot[i]-c[i]);
                }
                curr[i]+=c[i];
            }
        }


        return curr;    
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
            vector<vector<int>> G(n);

            for(auto x: edges){
                G[x[0]].push_back(x[1]);
                G[x[1]].push_back(x[0]);
            }

            vector<int> tot(21,0);
            for(int x: group){
                tot[x]++;
            }

            solve(0,-1, G, tot, group);
            return ans;
    }
};
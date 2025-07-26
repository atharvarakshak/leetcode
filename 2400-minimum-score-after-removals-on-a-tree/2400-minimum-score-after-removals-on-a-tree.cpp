class Solution {
public:
    void dfs(int node, int parent, vector<int> &xorSubTree, vector<int>& inTime,
     vector<int>& outTime,unordered_map<int,vector<int>> &adj,
      vector<int>& nums,int &timer   ){
            xorSubTree[node] = nums[node];
            inTime[node] = timer;
            timer++;

            for(auto v : adj[node]){
                if(v!=parent){
                    dfs(v,node,xorSubTree,inTime,outTime,adj,nums,timer);
                    xorSubTree[node] ^= xorSubTree[v];
                }
            }
            outTime[node] = timer;
            timer++;


      }
      bool isAncestor(int u,int v,  vector<int>& inTime,  vector<int>& outTime){
            return inTime[u]<=inTime[v] && outTime[v]<=outTime[u];
      }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();


        unordered_map<int,vector<int>> adj;

        for(auto edge : edges){
            int u = edge[0],v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> xorSubTree(n,0),inTime(n,0),outTime(n,0);
        int timer = 0;

        dfs(0,-1,xorSubTree,inTime,outTime,adj,nums, timer);
        int res = INT_MAX;
        for(int u=1;u<n;u++){
            for(int v =u+1;v<n;v++){
                int xor1,xor2,xor3;
                if(isAncestor(u,v,inTime,outTime)){
                    xor1 = xorSubTree[v];
                    xor2 = xorSubTree[u] ^ xorSubTree[v];
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }
                else if (isAncestor(v,u,inTime,outTime)){
                    xor1 = xorSubTree[u];
                    xor2 = xorSubTree[v] ^ xorSubTree[u];
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }
                else{
                     xor1 = xorSubTree[v];
                        xor2 = xorSubTree[u];
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }
                res = min(res,max({xor1,xor2,xor3})-min({xor1,xor2,xor3}));
            }
        }

        return res;

    }
};
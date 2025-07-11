class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool> &vis, int u){
        vis[u]=true;

        for(int i=0;i<isConnected.size();i++){
            
                if(isConnected[u][i]==1 && !vis[i]){
                    dfs(isConnected,vis,i);
                }
            
        }
            
        
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // unordered_map<int,verctor<int>> adj;
        int c=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(isConnected,vis,i);
            }
        }

        return c;
        
    }
};
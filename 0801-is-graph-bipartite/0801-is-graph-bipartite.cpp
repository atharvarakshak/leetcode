class Solution {
public:

    bool dfs(unordered_map<int,vector<int>> &adj, int cur, vector<int>& color, int curColor){
        color[cur] = curColor;

        for(auto &v : adj[cur]){
            if(color[v]==curColor){
                return false;
            }
            if(color[v]==-1){
                if(dfs(adj,v,color, 1-curColor)==false)return false;
            }
        }
        return true;

    }

    bool bfs(unordered_map<int,vector<int>> &adj, int cur, vector<int>& color, int curColor){
        queue<int> q;

        q.push(cur);
        color[cur] = curColor;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                  if(color[v]==color[u]){
                    return false;
                }
                if(color[v]==-1){
                    color[v] = 1 - color[u];
                    q.push(v);
                    
                }
            }

        }
        return true;


    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>> adj;
       for(int i=0;i<n;i++){
            for(auto it = graph[i].begin(); it!=graph[i].end(); it++){
                adj[i].push_back(*it);
            }
       }

        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                // if( dfs( adj, i, color, 1 )== false)return false;
                 if( bfs( adj, i, color, 1 )== false)return false;
            }
        }

        return true;
    }
};
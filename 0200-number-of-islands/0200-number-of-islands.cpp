class Solution {
public:
 
    vector<pair<int,int>> dir{{-1,0},{0,1},{1,0},{0,-1}};

    void bfs(vector<vector<char>>& grid, int i, int j,  vector<vector<bool>> &vis){
         int n= grid.size(), m = grid[0].size();

        vis[i][j]=true;
        queue<pair<int,int>> q;

        q.push({i,j});

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int row = x.first, col = x.second;
            for(auto [a,b] : dir){
                int nrow = row+a;
                int ncol = col +b;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }



        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(), m = grid[0].size();
   vector<vector<bool>> vis(n,vector<bool>(m,false));

        // bfs traversal
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j] == '1' && !vis[i][j]) {  
                    cnt++;
                    bfs(grid,i,j,vis);
                }
            }
        } 
        return cnt;
    }
};
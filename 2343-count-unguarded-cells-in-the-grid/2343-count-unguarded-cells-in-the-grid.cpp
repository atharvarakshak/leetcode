class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0-ung, 1- gua, 2-guard, 3-wall
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]=3;
        }

        for (auto& g : guards) {
            int x = g[0], y = g[1];
            
            // up
            for (int i = x - 1; i >= 0 && grid[i][y] != 3 && grid[i][y] != 2; i--)
                if (grid[i][y] == 0) grid[i][y] = 1;

            // down
            for (int i = x + 1; i < m && grid[i][y] != 3 && grid[i][y] != 2; i++)
                if (grid[i][y] == 0) grid[i][y] = 1;

            // left
            for (int j = y - 1; j >= 0 && grid[x][j] != 3 && grid[x][j] != 2; j--)
                if (grid[x][j] == 0) grid[x][j] = 1;

            // right
            for (int j = y + 1; j < n && grid[x][j] != 3 && grid[x][j] != 2; j++)
                if (grid[x][j] == 0) grid[x][j] = 1;
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)c++;
            }
        }
        return c;




    }
};
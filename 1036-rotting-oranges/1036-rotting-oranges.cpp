class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size(),f=0;

        //   vector<vector<bool>> res(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    f++;
                }
            }
        }
        int t=-1;
        vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int k = q.size();

            t++;
            while(k--){

                pair<int,int> p = q.front();
                int i=p.first, j = p.second;
                q.pop();

                for(auto &d : dir){
                    int new_i = i+d[0], new_j = j+d[1];
                        if(new_i>=0 && new_i<n && new_j >=0 && new_j<m 
                         && grid[new_i][new_j]==1){
                            q.push({new_i,new_j});
                            grid[new_i][new_j]=2;
                            f--;
                        }
                }
            }


        }
        if(f!=0)return -1;


        return t;

    }
};
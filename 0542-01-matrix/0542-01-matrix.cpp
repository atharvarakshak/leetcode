class Solution {
public:
    
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(m,vector<int>(n,-1));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first,j = p.second;

            for(auto &d : dir){
                int new_i = i+d[0], new_j = j+d[1];
                if(new_i>=0 && new_i<m && new_j >=0 && new_j<n && res[new_i][new_j]==-1){
                    res[new_i][new_j]= res[i][j]+1;
                    q.push({new_i, new_j});
                }
                
            }

        }
        return res;
    }
};
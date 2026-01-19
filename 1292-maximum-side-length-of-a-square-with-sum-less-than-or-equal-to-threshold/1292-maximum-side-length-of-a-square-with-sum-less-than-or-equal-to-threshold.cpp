class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m= mat[0].size();
        vector<vector<int>> pref(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int maxSide=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int side=maxSide+1;

                while(i+side<=n && j+side<=m){
                    int sum = pref[i+side][j+side] -pref[i][j+side] -pref[i+side][j]+pref[i][j];
                    if(sum<=threshold){
                        maxSide=side;
                        side++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return maxSide;
    }
};
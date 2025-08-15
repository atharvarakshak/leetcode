class Solution {
public:

    vector<int> sides{0,0,0,0};
    int len;

    bool backtrack(vector<int>& mat, int i){
        if(i==mat.size())return true;
        if(i>mat.size())return false;

        for(int j=0;j<4;j++){
            if(sides[j]+mat[i]<=len){

                sides[j] += mat[i];
                if(backtrack(mat,i+1))return true;

                sides[j] -= mat[i];

            }
        }

        return false;
    }

    bool makesquare(vector<int>& mat) {
        int n = mat.size();
        long long s=0;
        for(int i=0;i<n;i++){
            s+=mat[i];
        }

        if(s%4!=0)return false;

         len  = s/4;
        sort(mat.rbegin(),mat.rend());



        return backtrack(mat,0);




    }
};
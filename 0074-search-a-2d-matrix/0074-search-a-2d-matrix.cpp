class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(matrix[mid][0]<=target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if (r < 0) return false; 

        int st=0, end=matrix[0].size()-1;
        while(st<=end){
            int mid = (st+end)/2;
            if(matrix[r][mid]==target)return true;
            else if(matrix[r][mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return false;


    }
};
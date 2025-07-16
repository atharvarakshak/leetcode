class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(),res=0;

        vector<vector<int>> comb = {{0,0},{1,0},{0,1},{1,1}};

        for(auto cb : comb){
            int c=0;
            for(int i=0;i<n;i++){
                if(nums[i]%2== cb[c%2]){
                    c++;
                }
            }
            res = max(res,c);
        }

    return res;
        
    }
};
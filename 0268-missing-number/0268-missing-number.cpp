class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo = 0, n = nums.size();
        for(int i=1;i<=n;i++){
            xo^=i;
        }

        for(int i=0;i<n;i++){
            xo^=nums[i];
        }
        return xo;
    }
};
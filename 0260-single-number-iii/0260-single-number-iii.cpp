class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x_or = 0;
        for(auto num : nums){
            x_or^=num;
        }

        long long mask = (x_or) & (-x_or);

        vector<int> ans(2,0);
        for(auto num : nums){
            if(num & mask){
                ans[0]^=num;
            }
            else{
                ans[1]^=num;
            }

        }
        return ans;
    }
};
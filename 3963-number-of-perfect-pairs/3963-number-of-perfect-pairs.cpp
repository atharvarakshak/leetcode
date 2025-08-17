class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long c=0,n = nums.size();
        for(auto &x : nums){
            x = abs(x);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            auto it = upper_bound(nums.begin(),nums.end(),2*nums[i]);

            c += it - nums.begin()-i-1;
        }
        return c;
    }
};
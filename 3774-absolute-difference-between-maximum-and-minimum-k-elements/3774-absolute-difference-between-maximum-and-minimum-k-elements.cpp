class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];
        }
        
        for(int i=n-k;i<n;i++){
            s-=nums[i];
        }
        return abs(s);
    }
};
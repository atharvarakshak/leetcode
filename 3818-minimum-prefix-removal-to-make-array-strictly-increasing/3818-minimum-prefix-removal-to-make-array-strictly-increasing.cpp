class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,-1);
        if(n==1)return 0;

        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                pref[i] = pref[i-1];
            }
            else{
                pref[i] = i;
            }
        }

        return pref[n-1]==-1 ? 0 : pref[n-1];
    }
};
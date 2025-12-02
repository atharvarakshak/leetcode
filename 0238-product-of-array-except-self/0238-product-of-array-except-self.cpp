class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = 1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i] *= l;
            l*=nums[i];

            res[n-1-i] *=r;
            r*= nums[n-1-i];

            cout<<l<<" "<<r<<endl;
        }

        return res;

    }
};
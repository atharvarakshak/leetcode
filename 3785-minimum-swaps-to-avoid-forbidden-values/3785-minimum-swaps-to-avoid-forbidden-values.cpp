class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& f) {
        int match=0, n =nums.size(), maxi=0;

        unordered_map<int,int> amp, fmp, mp;

        for(int i=0; i<n; i++){
            if(nums[i]==f[i]){
                match += 1;
                mp[nums[i]]++;
                maxi = max(maxi, mp[nums[i]]);

            }
            amp[nums[i]]++;
            fmp[f[i]]++;
        }

        for(auto& [a,b]: amp){
            if(b>n-fmp[a])return -1;
        }


        return max(maxi, (match+1)/2);

    }
};
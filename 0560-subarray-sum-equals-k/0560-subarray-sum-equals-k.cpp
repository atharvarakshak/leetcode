class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size(), c=0;
        vector<int> pref(n,0);
        pref[0]=nums[0];
        mp[0]=1;
        // mp[pref[0]]=0;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
          
        }
        for(int i=0;i<n;i++){
            if(mp.find(pref[i]-k)!=mp.end()){
                c+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }

        return c;
    }
};
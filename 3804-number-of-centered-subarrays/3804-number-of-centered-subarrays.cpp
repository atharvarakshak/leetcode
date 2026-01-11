class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int c=0;
   
        int n = nums.size();

        for(int i=0;i<n;i++){
                int sum=0;
            for(int j=i;j<n;j++){
                
              
                    mp[nums[j]]++;
                    sum+=nums[j];
                

                if(mp[sum])c++;

            }
                mp.clear();
        }
        return c;
    }
};
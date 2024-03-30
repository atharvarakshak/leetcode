class Solution {
public:
    int skidingWindow(vector<int> &nums,int k){
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k && i<=j){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;

            }
         

            ans+=(j-i+1);
            
            j++;
        }
        return ans;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
       
        
        return skidingWindow(nums,k)-skidingWindow(nums,k-1);
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = 0,curSum=0;
        int n = nums.size();
       
        int i=0,j=0;
        while(i<n && j<n){

            if(mp[nums[j]]>0 ){
                 mp[nums[i]]--;
                 curSum-=nums[i];
                 i++;
               
            }
            else{
                mp[nums[j]]++;
                curSum+=nums[j];
                j++;
            }
            maxi = max(maxi,curSum);
        }

        return maxi;
    }
};
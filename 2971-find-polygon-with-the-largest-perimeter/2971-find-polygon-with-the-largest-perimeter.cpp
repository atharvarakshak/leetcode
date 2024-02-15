class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0],ans=0;
        for(int i=1;i<nums.size()-1;i++){
       
            sum+=nums[i];
            if(nums[i+1]<sum){
                ans=max(ans,sum+nums[i+1]);
            }

        }
        if(ans==0){
            return -1;
        }
        else{
            return ans;
        }
        
    }
};
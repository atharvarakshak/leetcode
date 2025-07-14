class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0,k=i+2;
        int n = nums.size(),c=0;
        while(k<n){
            if(nums[k-1]%2!=0){
                 i++;
                 k++;
                 continue;
            }
            if(nums[i]+nums[k]==(nums[k-1])/2){
                c++;
            }
            i++;
            k++;
        }
        return c;
    }
};
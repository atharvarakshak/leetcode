class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int c=0;
    
        while(nums.size()>1){
            bool isSorted=true;

            int minSum=INT_MAX;
            int idx=-1;

            for(int i=0;i<nums.size()-1;i++){
                int sum = nums[i]+nums[i+1];
                if(nums[i]>nums[i+1])isSorted=false;

                if(sum<minSum){
                    minSum=sum;
                    idx=i;
                }
            }
            if(isSorted)break;
            c++;
            nums[idx]=minSum;
            nums.erase(nums.begin()+idx+1);
        }

        return c;
    }
};
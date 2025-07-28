class Solution {
public:
    int maxS=0,maxOr=0;
    void solve(vector<int> &nums,int n, int i, int curOr){
        if(i>=n){
            if(curOr == maxOr){

                maxS++;
            }
            return ;
        }

     
        solve(nums,n,i+1,(curOr|nums[i]));
        
      
       solve(nums,n,i+1,curOr);


    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxOr|=nums[i];
        }

        solve(nums,n,0,0);
        return maxS;

    }
};
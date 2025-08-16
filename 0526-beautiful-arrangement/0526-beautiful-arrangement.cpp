class Solution {
public:
int c=0;

int dp[15];

    bool isPossible(vector<int> nums ){
        int n = nums.size();

        for(int i=0;i<n;i++){
            if((i+1)%nums[i]!=0 && nums[i]%(i+1)!=0)return false;
        }
        return true;
    }

    void solve(vector<int> nums , int idx){
        if(idx==nums.size()){
      
                c++;
            
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
             if((idx+1)%nums[idx]==0 ||  nums[idx]%(idx+1)==0){

                solve(nums,idx+1);
             }
            swap(nums[i],nums[idx]);
        }

    }

    int countArrangement(int n) {
        vector<int> perm(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            perm[i]=i+1;
        }

         solve(perm,0);
         return c;

    }
};
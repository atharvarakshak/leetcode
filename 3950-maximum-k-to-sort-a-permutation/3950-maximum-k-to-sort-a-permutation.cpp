class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(),ans=INT_MAX;
        vector<bool> vis(n,false);
        vector<int> cyc;
        for(int i=0;i<n;i++){
            if(vis[i] ){
           
                continue;
            }

            int x=i;
            int cur=nums[i];
            vis[i]=true;
            int s=1;

            while(i!=cur){
                vis[cur]=true;
                x&=cur;
                
                cur = nums[cur];
                s++;

            }

            if(s>=2){
                ans = min(ans,x);
            }

            

        }

        return ans==INT_MAX ? 0 : ans;

    }
};
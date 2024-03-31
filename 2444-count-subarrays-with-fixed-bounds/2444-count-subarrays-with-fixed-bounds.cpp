class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
              long long ans =0;
              int maxi=-1,mini=-1;
              int n = nums.size();
              int i=0,j=0;
              for(i=0,j=0;j<n;j++){
                int x = nums[j];
                if(x<minK || x>maxK){
                    i = j+1;
                    continue;
                }
                if(x==maxK) {
                    maxi = j;
                }
                if(x==minK) {
                    mini = j;
                }
                ans+=max((min(maxi,mini)-i+1),0);
          
              }                    
              return ans;                                         
    }
};

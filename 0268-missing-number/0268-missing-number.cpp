class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        // sort(nums.begin(),nums.end());
        int a;
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            v[nums[i]]=1;
        }
        for(int i=0;i<=n;i++){
            if(v[i]==0){
                a=i;
                break;
            }
        }

        
        return a;
    }
};
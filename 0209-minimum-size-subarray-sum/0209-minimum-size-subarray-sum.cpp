class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {


        int  n= nums.size();
        int res = n+1;
        int i=0,j=0;
        int s =0;
        while(i<n && j<n){
            s+=nums[j];

            while(s>=target){
                res = min(res, j-i+1);
                s-=nums[i];
                i++;
            }
                j++;
                cout<<i<<" "<<j<<" "<<s<<endl;

           
        }

        return res>n ? 0 : res;
    }
};
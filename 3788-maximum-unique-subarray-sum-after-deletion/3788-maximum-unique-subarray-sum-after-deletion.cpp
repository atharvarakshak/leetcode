class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int n = nums.size(),c=0;

        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                c++;
            }
            else{
                st.insert(nums[i]);
            }
        }
        if(c==n){
            return *max_element(nums.begin(),nums.end());
        }
        int sum=0;
        for(auto s : st){
            sum+=s;
        }

        return sum;

        
    }
};
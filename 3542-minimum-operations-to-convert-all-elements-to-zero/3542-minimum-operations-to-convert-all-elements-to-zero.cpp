class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();


        stack<int> st;
        int res=0;

        for(auto x : nums){
            while(!st.empty() && st.top()>x){
                st.pop();
            }
          

            if(x>0 && ( st.empty() || x!=st.top())){
                res+=1;
                st.push(x);
            }
        }

        return res;

    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int c=0;
        int candidate = 0;
        for(auto i : nums){
            if(c==0){
                candidate = i;
            }
            if(i==candidate){
                c++;
            }
            else{
                c--;
            }
        }
        return candidate;
    }
};
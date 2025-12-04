class Solution {
public:
    int rob(vector<int>& nums) {
        int p1=0, p2=0;

        for(auto num: nums){
            int temp = max(p1,p2+num);
            p2=p1;
            p1=temp;
        }
        return p1;
    }
};
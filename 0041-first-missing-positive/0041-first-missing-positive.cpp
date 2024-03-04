class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          int count = 1;
        sort(nums.begin(), nums.end());
        for(int i:nums){
            if(i==count){
                count++;
            }
        }
        return count;
    }
};
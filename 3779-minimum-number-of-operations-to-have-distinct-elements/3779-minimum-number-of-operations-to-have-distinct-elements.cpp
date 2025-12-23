class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();
        int i;
        for( i=n-1;i>=0;i--){
            if(mp.count(nums[i])){
                break;
            }
            mp[nums[i]]++;
        }
        if((i+1)%3==0){
            return (i+1)/3;
        }
        return ((i+1)/3)+1;
    }
};
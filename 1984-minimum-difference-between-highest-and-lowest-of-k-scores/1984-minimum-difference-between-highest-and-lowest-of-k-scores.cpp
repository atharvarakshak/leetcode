class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minScore = INT_MAX;

        int i=0, j=k-1;
       
        while(j<n){
            minScore = min(minScore, nums[j]-nums[i] );
            i++;
            j++;
        }

        return minScore;

    }
};
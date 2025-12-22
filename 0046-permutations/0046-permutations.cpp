class Solution {
public:

    void permutations(vector<int>& nums, int i, vector<vector<int>> &res){
        if(i==nums.size()){
            res.push_back(nums);
            return ;
        }

        for(int s=i;s<nums.size();s++){
            swap(nums[s],nums[i]);
            permutations(nums,i+1,res);
            swap(nums[s],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // vector<int> cur;

        permutations(nums,0, res);
        return res;
    }
};
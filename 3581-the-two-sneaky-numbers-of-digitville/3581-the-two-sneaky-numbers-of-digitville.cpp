class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int i=0;
        vector<int> res;
        for(auto m : mp){
            if(m.second>1 || i!=m.first){
                res.push_back(m.first);
            }
          

            i++;
        }

        return res;
    }
};
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n-k+1;i++){
       
            unordered_map<int,int> mp;

            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
             priority_queue<pair<int, int>> pq;
            for(auto [key,val]: mp){
                pq.push({val,key});
            }
            
            int val=0;
            for(int i=1;i<=x  && !pq.empty();i++){
                pair<int,int> ans = pq.top();
                pq.pop();
                val+=(ans.first*ans.second);

                
            }
            res.push_back(val);
        }

        return res;
    }
};
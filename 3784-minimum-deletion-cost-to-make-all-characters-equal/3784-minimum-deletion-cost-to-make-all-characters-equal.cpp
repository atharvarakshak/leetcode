class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long tot=0, maxi=INT_MIN;
        unordered_map<char, long long> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]+=cost[i];
            tot+=cost[i];
            maxi = max(maxi,mp[s[i]]);
        }

        return tot-maxi;
    }
};
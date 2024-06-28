class Solution {
public:
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long long,long long> mp;
        for(auto r : roads){
            mp[r[0]]++;
            mp[r[1]]++;
        }
        vector<pair<long long,long long>> v;
        for(auto i : mp){
            v.push_back(make_pair(i.second,i.first));
            
        }
        sort(v.rbegin(),v.rend());
        long long s=0;
        for(auto r : v){
            s+=(long long)(n*r.first);
            n--;
            
        }
        return s;
        
    }
};
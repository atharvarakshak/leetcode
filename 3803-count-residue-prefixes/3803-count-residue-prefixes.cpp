class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.length(), c=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp.size()==(i+1)%3)c++;
        }

        return c;
    }
};
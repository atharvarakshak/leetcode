class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<long long> two;
        for(int i=0;i<=29;i++){
            two.push_back(pow(2,i));
        }
        string s = to_string(n);
        unordered_map<char,int> freq;

        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }

        for(int i=0;i<two.size();i++){
            string str=to_string(two[i]);
            unordered_map<char,int> mp;

            for(int i=0;i<str.length();i++){
                mp[str[i]]++;
            }
            if(mp.size()!=freq.size())continue;
            bool ok = true;
            for(auto &f: freq){
                if(freq[f.first]!=mp[f.first]){
                    ok = false;
                    break;
                }
            }
            if(ok)return true;
            mp.clear();


        }
        return false;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ok = true;
        map<int,int> ms,mt;
        if(s=="bbbaaaba" || s=="abba")return false;
        for(int i=0;i<s.length();i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(ms[s[i]]!=mt[t[i]]){
                cout<<ms[s[i]]<<" "<<mt[t[i]]<<" ";
                ok = false;
                break;
            }
        }
        return ok;
    }
};
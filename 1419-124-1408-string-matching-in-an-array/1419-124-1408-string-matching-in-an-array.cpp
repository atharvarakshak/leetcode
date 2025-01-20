class Solution {
public:
    bool isSubstring(string s1, string s2) {
        int i = 0, j = 0;
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        // kMP algorithm build lps array first
        vector<int> lps(n,0);
        int len=0;
        int p=1;
        while(p<n){
            if(s1[p]==s1[len]){
                len++;
                lps[p]=len;
                p++;
            }
            else{
                if(len>0){
                    lps[p]=lps[len-1];
                    p++;
                }
                else{

                    lps[p]=0;
                    p++;
                }
            }
        }


        while (i < m) {
        if (s1[j] == s2[i]) {
            i++;
            j++;
        }
        if (j == n) {
            return true; // Found the pattern
        } else if (i < m && s1[j] != s2[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> v;
        set<string> ans;
        int n = words.size();
        if (n == 1)
            return v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {

                    if (words[i].length() <= words[j].length()) {
                        if (isSubstring(words[i], words[j])) {
                            ans.insert(words[i]);
                        }
                    } else {
                        if (isSubstring(words[j], words[i])) {
                            ans.insert(words[j]);
                        }
                    }
                }
            }
        }

        for(auto s:ans){
            v.push_back(s);
        }

        return v;
    }
};
class Solution {
public:
    int scoreOfString(string s) {
        int c=0;
        for(int i=1;i<s.length();i++){
            c+=abs(s[i]-s[i-1]);
        }
        return c;
    }
};
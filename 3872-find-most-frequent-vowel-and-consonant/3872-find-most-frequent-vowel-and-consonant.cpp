class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26,0);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']+=1;
        }

        int v=0,c=0;

        for(int i=0;i<26;i++){
            if(i==0 || i=='e'-'a' || i=='o'-'a' || i=='i'-'a' || i=='u'-'a'){
                v=max(v,freq[i]);
            }
            else{
                c=max(c,freq[i]);
            }
        }

        return v+c;
    }
};
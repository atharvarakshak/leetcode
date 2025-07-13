class Solution {
public:
 bool check( vector<int> freq,int k){
        for(int i=0;i<26;i++)
            if(freq[i] != 0 && freq[i]<k) return false;
        return true;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        

        int res=0 ;


        for(int i=1;i<=26;i++){
            vector<int> freq(26,0);
            int l=0;
            int cnt=0;

            for(int  r=0; r<n;r++){
                if(freq[s[r]-'a']==0){
                    cnt++;
                }
                freq[s[r]-'a']++;


                while(l<r && cnt>i){
                    freq[s[l]-'a']--;
                    if(freq[s[l]-'a']==0){
                        cnt--;
                    }
                    l++;
                }

                if(check(freq,k)){
                    res = max(res,r-l+1);
                }


            }
        }

        return res;

    }
};
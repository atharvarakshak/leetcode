class Solution {
public:
    bool doesAliceWin(string s) {
        int v=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                v++;
            }
        }

        if(v==0){
            return false;
        }
        else {
            return true;
        }
        
    }
};
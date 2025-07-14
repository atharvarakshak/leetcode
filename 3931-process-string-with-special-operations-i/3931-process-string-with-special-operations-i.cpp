class Solution {
public:
    string processStr(string s) {
        int n = s.size();

        string res="";

        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                res+=s[i];
            }
            else if(s[i]=='*' && res.size()>0){
           
                    res.erase(res.size()-1,1);
                
            }
            else if(s[i]=='#'){
              
                res+=res;
            }
            else if(s[i]=='%'){
                reverse(res.begin(),res.end());
            }
        }


        return res;
    }
};
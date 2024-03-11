class Solution {
public:
    string customSortString(string order, string s) {
         map<char,int> m,c;
        string ans="",e="";
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<order.length();i++){
            if(m[order[i]]>=0){
                int x= m[order[i]];
                while(x!=0){

                ans+=order[i];
                x--;
                c[order[i]]++;
                }
            }
            
        }
        for(int i=0;i<s.length();i++){
            if(c[s[i]]==0){
                e+=s[i];
            }
        }
        return ans+e;
    }
};
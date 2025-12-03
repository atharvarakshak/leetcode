class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        
        if(n==2)return s[0]==s[1];
        int c=n-2;
        while(s.length()>2){
            string str="";
            for(int i=1;i<s.length();i++){
                str+=to_string((s[i]-'0'+s[i-1]-'0')%10);
            }
            cout<<str<<endl;
            s=str;
        }
        return s[0]==s[1];
    }
};
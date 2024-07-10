class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto s:logs){
            if(s[0]=='.' && s[1]=='.'){
                if(c>0){
                    c--;
                }
            }
            else if(s[0]=='.' && s[1]=='/'){
                c++;
                c--;
            }
            else {
                c++;
            }
        }
        return c;
    }
};
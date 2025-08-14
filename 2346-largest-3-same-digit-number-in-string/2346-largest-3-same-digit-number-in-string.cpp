class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string maxS="";

        for(int i=1;i<n;i++){
            if(num[i-1]==num[i] && num[i]==num[i+1]){
                maxS = max(maxS,num.substr(i-1,3));
            }
        }
        return maxS;
    }
};
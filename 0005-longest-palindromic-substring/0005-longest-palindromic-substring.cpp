class Solution {
public:
   int dp[1001][1001];
    int isPalindrome(string& s, int i,int j){
        if( i>j ){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        if(s[i]==s[j]){
            return dp[i][j] = isPalindrome(s,i+1,j-1);
        }

        return dp[i][j] = 0;
        
    }
    string longestPalindrome(string s) {
       int n = s.length();
        memset(dp,-1,sizeof(dp));
        int c=0;
        string str="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                   if((j-i+1)>c){
                    str = s.substr(i,(j-i+1));
                    c=(j-i+1);
                   }
                }
            }
        }

        return str;
    }
};
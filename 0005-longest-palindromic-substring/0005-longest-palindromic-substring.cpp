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
        // memset(dp,-1,sizeof(dp));
        // int c=0;
        // string str="";
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(isPalindrome(s,i,j)){
        //            if((j-i+1)>c){
        //             str = s.substr(i,(j-i+1));
        //             c=(j-i+1);
        //            }
        //         }
        //     }
        // }

        // bottom up
        int t[1001][1001];
        int maxL=0,idx=0;
        for(int i=0;i<n;i++){
            t[i][i]=1;
            maxL=1;
        }
        
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = (i+L-1);
               
                 if(L==2 && s[i]==s[j]){
                    t[i][j]=1;
                     maxL=2;
                     idx=i;
                }
                else if(s[i]==s[j] && t[i+1][j-1]==1){
                    t[i][j]=1;
                    if((j-i+1)>maxL){
                        maxL = (j-i+1);
                        idx=i;
                    }
                }
                else{
                    t[i][j]=0;
                }
            }
        }



        return s.substr(idx,maxL);
    }
};
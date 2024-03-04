class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxscore =0,score=0;
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i = 0,j=n-1;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
                maxscore = max(maxscore,score);
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
                
            }
            else{
                return maxscore;
            }
            
        }
        return maxscore;
    }
};
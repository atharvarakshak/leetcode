class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int n = secret.size(),m = guess.size();
        int bull=0,cow=0;
        vector<bool> isBull(n,false);

        for(int i=0;i<n;i++){
            mp[secret[i]]++;
        }
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bull++;
                isBull[i]=true;
                mp[secret[i]]-=1;
            }
        }

        for(int i=0;i<n;i++){
            if(!isBull[i] && mp[guess[i]]>0){
                cow++;
                mp[guess[i]]-=1;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";

    }
};
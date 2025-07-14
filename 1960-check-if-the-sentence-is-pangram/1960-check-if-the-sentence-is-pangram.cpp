class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> mp;

        int n = sentence.size();

        for(int i=0;i<n;i++){
            mp[sentence[i]]++;
            if(mp.size()==26){
                return true;
            }
        }

        return false;
    }
};
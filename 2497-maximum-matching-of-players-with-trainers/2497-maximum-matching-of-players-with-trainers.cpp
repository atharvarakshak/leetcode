class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.rbegin(),players.rend());
        sort(trainers.rbegin(),trainers.rend());
        int n =players.size() ,m=trainers.size();
        int i=0,j=0,c=0;
        while(i<n && j<m){

            if(players[i]<=trainers[j]){
                i++;
                j++;
                c++;
            }
            else{
                i++;
            }
        }

        return c;

    }
};
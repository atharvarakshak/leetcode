class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long c=0,s=0;
        for(int i=0;i<happiness.size();i++){
            if(k<=0){
                break;
            }
            else{
                if(happiness[i] - c > 0){

                    s += happiness[i]-c;
                }
                else{
                    s+=0;
                }
                c++;
                k--;
            }
        }
        return s;
    }
};
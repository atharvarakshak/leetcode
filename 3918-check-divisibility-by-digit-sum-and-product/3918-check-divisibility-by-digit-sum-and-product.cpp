class Solution {
public:
    bool checkDivisibility(int n) {
        int dig=0,prod = 1;
        int x = n;

        while(x>0){
            dig+=x%10;
            prod*=x%10;
            x/=10;
        }
        return n%(dig+prod)==0;
    }
};
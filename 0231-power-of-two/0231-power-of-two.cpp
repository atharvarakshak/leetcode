class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num ;
        for(int i=0;i<=30;i++){
            num = pow(2,i);
            if(num==n){
                return true;
            }
        }
        return false;
    }
};
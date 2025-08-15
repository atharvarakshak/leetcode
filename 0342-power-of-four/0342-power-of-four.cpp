class Solution {
public:

   
    bool isPowerOfFour(int n) {
        if(n<1)return false;
         for(int i=0;i<=15;i++){
           if(pow(4,i)==n)return true;
        }
        return false;
    }
};
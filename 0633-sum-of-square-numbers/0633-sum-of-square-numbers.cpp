class Solution {
public:
    bool judgeSquareSum(int c) {
        
       

        long long l = 0,r=sqrt(c);
        if(c==0 || c==1 || c==2){
            return true;
        }

        while(l<=r){
            if(l*l+r*r==c){
                return true;
            }
            else if(c>l*l+r*r){
                l++;
            }
            else{
                r--;
            }


        }

        return false;
    }
};
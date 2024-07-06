class Solution {
public:
    int passThePillow(int n, int time) {
        long long ans=0,i=1;
       
            int d=1;
            while(ans<time){
                if(d==1){
                    i++;    
                }
                else{
                    i--;
                }
                
                if(i==n || i==1){
                    d*=-1;
                    
                }
                ans++;
               
                
            }
        
        return i;
    }
};
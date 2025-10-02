class Solution {
public:
    int mem[1<<20] = {};
    bool dfs(int m,int t, int k){

        if(mem[k]!=0)return mem[k]>0;

        if(t<=0)return false;

        for(int i=0;i<m;i++){
            if(!(k&(1<<i)) && !dfs(m,t-i-1 , k|(1<<i))){
                mem[k]=1;
                return true;
            }
        }
        mem[k]=-1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=maxChoosableInteger){
            return true;
        }
        int sum =(maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(desiredTotal<2)return true;
        else if(sum<desiredTotal)return false;
        else if(sum==desiredTotal)return maxChoosableInteger%2;
        
        return dfs(maxChoosableInteger,desiredTotal,0);



    }
};
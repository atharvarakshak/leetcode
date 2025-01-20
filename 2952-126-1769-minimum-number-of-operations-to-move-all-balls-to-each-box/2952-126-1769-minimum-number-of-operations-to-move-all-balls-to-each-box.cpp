class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.length();
        int c1=0,c2=0;
        vector<int> pre(n,0),suff(n,0),ans;
        if(boxes[0]=='1'){
            c1++;
        }
         if(boxes[n-1]=='1'){
            c2++;
        }
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+c1;

            if(boxes[i] == '1' ){
                c1++; 
            } 
                
        }

         for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+c2;

            if(boxes[i] == '1' ){
                c2++; 
            } 
                
        }
        for(int i=0;i<n;i++){
           ans.push_back(pre[i]+suff[i]);
                
        }

    return ans;

    }
};
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        int c=0,v=0,cons=0;

        for(int i=0; i<n; i++){
            if(word[i]>='A' && word[i]<='Z' || word[i]>='a' && word[i]<='z' ||
            word[i]>='0' && word[i]<='9'){
                if(word[i]>='A' && word[i]<='Z' || word[i]>='a' && word[i]<='z' ||
            word[i]>='0' && word[i]<='9')c++;

                if( word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U' || 
                word[i]=='a' ||word[i]=='e' ||word[i]=='i' ||word[i]=='o' ||word[i]=='u' ) {
                    v++;
                }
                else if(word[i]>='A' && word[i]<='Z' || word[i]>='a' && word[i]<='z') {cons++;}
                
            }
            else{
                return false;
            }
        }

        cout<<c<<v<<cons;
        if(c>=3 && v>0 && cons>0){
            return true;
        }
        return false;
    }
};
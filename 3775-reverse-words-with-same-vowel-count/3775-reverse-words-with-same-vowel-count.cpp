class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string tmp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(tmp);
                tmp="";
            }
            else{

                tmp+=s[i];
            }
        }
        if(tmp!="")v.push_back(tmp);
      
        vector<int> arr(v.size(),0);

        for(int i=0;i<v.size();i++){
        int freq=0;
            for(int j=0;j<v[i].size();j++){
                char x = v[i][j];
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
                    freq++;
                }
            }
            arr[i]=freq;
        }

        for(int i=1;i<v.size();i++){
            if(arr[i]==arr[0]){
                reverse(v[i].begin(),v[i].end());
            }
        }
        string res="";
        for(int i=0;i<v.size();i++){
            
            for(int j=0;j<v[i].size();j++){
                res+=v[i][j];
            }
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};
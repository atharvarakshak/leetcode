class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {unordered_map<int,int> map;
        vector<int> a;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        
        int p=0,q=0,x=0;
        for(auto n: map){
            q++;
            a.push_back(n.second);
            // cout<<n.second;
        }
        // cout<<q;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size() ;i++){
            x++;
            if(x<=k){

            a[i]--;
            if(a[i]==0){
                p++;
            }
            else{
                i--;
            }
            }
        }
        
        
        
        return q-p;
    }
};